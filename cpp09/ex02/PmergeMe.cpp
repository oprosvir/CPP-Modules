/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:12:54 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/07 02:26:10 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <iomanip>

// canonical form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vec(other._vec), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// check if string is a positive integer
static bool isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    long val = std::strtol(str.c_str(), NULL, 10);
    return val > 0 && val <= INT_MAX;
}

void PmergeMe::load(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isValidNumber(arg)) {
            throw std::runtime_error("Error: invalid input");
        }
        int num = std::atoi(arg.c_str());
        _vec.push_back(num);
        _deque.push_back(num);
    }
}

static void insertWithBinarySearchVector(std::vector<int>& vec, int value) {
    std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    std::vector<int> mainChain;
    std::vector<int> pend;

    // split into pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int first = vec[i];
        int second = vec[i + 1];
        if (first > second) std::swap(first, second);
        mainChain.push_back(second);
        pend.push_back(first);
    }
    
    // if odd size, last element remains
    if (vec.size() % 2 != 0) {
        mainChain.push_back(vec.back());
    }

    // Sort mainChain recursively
    mergeInsertSortVector(mainChain);

    // Insert pending elements one by one using binary search
    for (size_t i = 0; i < pend.size(); ++i)
        insertWithBinarySearchVector(mainChain, pend[i]);

    vec = mainChain;
}

void PmergeMe::process() {
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertSortVector(_vec);
    clock_t endVec = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << timeVec << " us" << std::endl;
}