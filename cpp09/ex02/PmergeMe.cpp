/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:12:54 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/16 02:35:20 by oprosvir         ###   ########.fr       */
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
    if (argc < 2)
        throw std::runtime_error("Usage: ./PmergeMe <sequence of positive integers>");
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

// Jacobsthal sequence for insertion order
static std::vector<size_t> generateJacobsthalSeq(size_t size) {
    std::vector<size_t> result;
    std::set<size_t> used;
    size_t j0 = 0, j1 = 1;
    size_t jn;

    while ((jn = j1 + 2 * j0) < size) {
        if (used.insert(j1).second)
            result.push_back(j1);
        j0 = j1;
        j1 = jn;
    }

    for (size_t i = 0; i < size; ++i) {
        if (used.insert(i).second)
            result.push_back(i);
    }

    return result;
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pend;

    // 1. Split into pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int first = vec[i];
        int second = vec[i + 1];
        
        if (first > second)
            std::swap(first, second);
            
        mainChain.push_back(second);
        pend.push_back(first);
    }
    
    // if odd size, add the last element to pend
    if (vec.size() % 2 != 0) {
        pend.push_back(vec.back());
    }

    // 2. Sort mainChain recursively
    mergeInsertSort(mainChain);

    std::vector<size_t> insertionOrder = generateJacobsthalSeq(pend.size());

    // 3. Insert elements from pend into mainChain
    // using binary search for insertion
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        if (insertionOrder[i] >= pend.size())
            continue;
        binaryInsert(mainChain, pend[insertionOrder[i]]);
    }

    vec = mainChain;
}

void PmergeMe::mergeInsertSort(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pend;

    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        int first = deq[i];
        int second = deq[i + 1];
        
        if (first > second)
            std::swap(first, second);
            
        mainChain.push_back(second);
        pend.push_back(first);
    }

    if (deq.size() % 2 != 0)
        pend.push_back(deq.back());

    mergeInsertSort(mainChain);

    std::vector<size_t> insertionOrder = generateJacobsthalSeq(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        if (insertionOrder[i] >= pend.size())
            continue;
        binaryInsert(mainChain, pend[insertionOrder[i]]);
    }

    deq = mainChain;
}

void PmergeMe::process() {
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertSort(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertSort(_deque);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;
    
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << timeVec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << timeDeq << " us" << std::endl;
}