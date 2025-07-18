/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:13:05 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/18 02:27:20 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void checkArgs(int argc, char** argv);
    void process(int argc, char** argv);

private:
    std::vector<int> _input;

    void mergeInsertSort(std::vector<int>& data);
    void mergeInsertSort(std::deque<int>& data);

    template <typename Container>
    Container generateInsertionOrder(size_t size);

    template <typename Container>
    void binaryInsert(Container &container, int value);
    
};

template <typename Container>
Container PmergeMe::generateInsertionOrder(size_t size) {
    Container result;
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

template <typename Container>
void PmergeMe::binaryInsert(Container &container, int value) {
    typename Container::iterator begin = container.begin();
    typename Container::iterator end = container.end();

    while (begin < end) {
        typename Container::iterator mid = begin + (end - begin) / 2;
        if (*mid < value)
            begin = mid + 1;
        else
            end = mid;
    }
    container.insert(begin, value);
}

#endif