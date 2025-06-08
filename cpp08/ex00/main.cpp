/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:52:48 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/08 20:22:57 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main(void) {
    std::cout << "--- std::vector (mutable, duplicates) ---" << std::endl;
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    std::cout << "Vector before: ";
    printContainer(v);
    
    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it << std::endl;
        *it = 42;
        std::cout << "Modified to: " << *it << std::endl;
        std::cout << "Vector after modification: ";
        printContainer(v);
        std::cout << "Inserting before modified element ..." << std::endl;
        v.insert(easyfind(v, 42), 99);
        std::cout << "Vector after insert: ";
        printContainer(v);
        std::cout << "Erasing modified element ..." << std::endl;
        v.erase(easyfind(v, 42));
        std::cout << "Vector after erase: ";
        printContainer(v);
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::cout << "\n--- std::list (const) ---" << std::endl;
    std::list<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_front(5);
    temp.push_front(30);
    const std::list<int> l = temp;
    
    std::cout << "List: ";
    printContainer(l);

    try {
        std::list<int>::const_iterator it = easyfind(l, 2);
        std::cout << "Found in const list: " << *it << std::endl;
        // *it = 42; // compile error
    } catch (const std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    std::cout << "\n--- std::deque (direct access) ---" << std::endl;
    std::deque<int> d;
    d.push_back(100);
    d.push_front(50);
    d.push_back(150);

    std::cout << "Deque before: ";
    printContainer(d);

    try {
        std::cout << "Modifying element directly: " << *easyfind(d, 100) << " -> ";
        *easyfind(d, 100) = 777;
        std::cout << *easyfind(d, 777) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Deque: " << e.what() << std::endl;
    }

    std::cout << "Deque after: ";
    printContainer(d);

    std::cout << "\n--- std::set (ordered) ---" << std::endl;
    std::set<int> s;
    s.insert(42);
    s.insert(800);
    s.insert(-5);

    std::cout << "Set: ";
    printContainer(s);   // sorted

    try {
        std::set<int>::iterator it = easyfind(s, 100);
        std::cout << "Found in set: " << *it << std::endl;
        // *it = 999; // set is const
    } catch (const std::exception& e) {
        std::cout << "Set: " << e.what() << std::endl;
    }

    std::cout << "\n--- std::multiset (duplicates allowed) ---" << std::endl;
    std::multiset<int> ms;
    ms.insert(10000);
    ms.insert(-42);
    ms.insert(0);
    ms.insert(-42);

    std::cout << "Multiset before: ";
    printContainer(ms);

    try {
        std::multiset<int>::iterator it = easyfind(ms, -42);
        std::cout << "Found: " << *it << ", removing..." << std::endl;
        ms.erase(it);
    } catch (const std::exception& e) {
        std::cout << "Multiset: " << e.what() << std::endl;
    }

    std::cout << "Multiset after: ";
    printContainer(ms);
    
    return 0;
}