/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:12:54 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/18 02:25:00 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <iomanip>

// canonical form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _input(other._input) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        _input = other._input;
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

void PmergeMe::checkArgs(int argc, char** argv) {
    if (argc < 2)
        throw std::runtime_error("Usage: ./PmergeMe <sequence of positive integers>");
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isValidNumber(arg)) {
            throw std::runtime_error("Error: invalid input");
        }
        int num = std::atoi(arg.c_str());
        _input.push_back(num);
    }
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

    std::vector<size_t> insertionOrder = generateInsertionOrder<std::vector<size_t> >(pend.size());

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

    std::deque<size_t> insertionOrder = generateInsertionOrder<std::deque<size_t> >(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        if (insertionOrder[i] >= pend.size())
            continue;
        binaryInsert(mainChain, pend[insertionOrder[i]]);
    }

    deq = mainChain;
}

void PmergeMe::process(int argc, char** argv) {
    std::cout << "Before:";
    for (size_t i = 0; i < _input.size(); ++i)
        std::cout << " " << _input[i];
    std::cout << std::endl;

    // === VECTOR ===
    clock_t startVec = clock();
    std::vector<int> vec;
    for (int i = 1; i < argc; ++i)
        vec.push_back(std::atoi(argv[i]));
    mergeInsertSort(vec);
    clock_t endVec = clock();

    // === DEQUE ===
    clock_t startDeq = clock();
    std::deque<int> deq;
    for (int i = 1; i < argc; ++i)
        deq.push_back(std::atoi(argv[i]));
    mergeInsertSort(deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;
    
    double timeVec = static_cast<double>(endVec - startVec);
    double timeDeq = static_cast<double>(endDeq - startDeq);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << timeVec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << timeDeq << " us" << std::endl;
}