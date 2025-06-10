/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:31:00 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/10 21:20:04 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "../ex00/easyfind.hpp"
#include "../ex01/Span.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

int main(void) {
	std::cout << "--- MutantStack basic test ---" << std::endl;

	MutantStack<int> mstack;
    
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
    
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

    std::cout << "\n--- std::list comparison ---" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();
    
	std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
	std::stack<int, std::list<int> > clst(lst);

    std::cout << "\n--- Const MutantStack iteration ---" << std::endl;
    const MutantStack<int> constStack = mstack;
    printContainer(constStack);

    std::cout << "\n--- Copy and assignment ---" << std::endl;
    MutantStack<int> copy(mstack);
    MutantStack<int> assigned;
    assigned = mstack;

    std::cout << "Copy size: " << copy.size() << ", Assigned top: " << assigned.top() << std::endl;
    
    std::cout << "\n--- MutantStack<std::string> ---" << std::endl;

    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("Mutant");
    strStack.push("Stack");
    strStack.push("!");

    printContainer(strStack);

    std::cout << "Top string: " << strStack.top() << std::endl;

    std::cout << "After pop: ";
    strStack.pop();
    printContainer(strStack);

    std::cout << "Reversing: ";
    std::reverse(strStack.begin(), strStack.end());
    printContainer(strStack);
    
    std::cout << "\n--- STL algorithms on MutantStack ---" << std::endl;
    MutantStack<int> algostack;
    for (int i = 1; i <= 5; ++i)
        algostack.push(i * 10);  // 10, 20, 30, 40, 50
    
    std::cout << "Original: ";
    printContainer(algostack);

    std::cout << "\n--- std::find ---" << std::endl;
    MutantStack<int>::iterator found = std::find(algostack.begin(), algostack.end(), 30);
    if (found != algostack.end())
        std::cout << "Found 30 at position: " << std::distance(algostack.begin(), found) << std::endl;

    std::cout << "\n--- std::accumulate ---" << std::endl;
    int sum = std::accumulate(algostack.begin(), algostack.end(), 0);
    std::cout << "Sum of all elements: " << sum << std::endl;

    std::cout << "\n--- std::reverse ---" << std::endl;
    std::reverse(algostack.begin(), algostack.end());
    std::cout << "After reverse: ";
    printContainer(algostack);

    std::cout << "\n--- std::sort (reverse back) ---" << std::endl;
    std::sort(algostack.begin(), algostack.end());
    std::cout << "After sort:    ";
    printContainer(algostack);

    std::cout << "\n--- std::min_element, std::max_element ---" << std::endl;
    MutantStack<int>::iterator minIt = std::min_element(algostack.begin(), algostack.end());
    MutantStack<int>::iterator maxIt = std::max_element(algostack.begin(), algostack.end());
    if (minIt != algostack.end())
        std::cout << "Min element: " << *minIt << std::endl;
    if (maxIt != algostack.end()) {
        std::cout << "Max element: " << *maxIt << std::endl;
    }

    std::cout << "\n--- easyfind on MutantStack ---" << std::endl;
    MutantStack<int> efstack;
    efstack.push(1);
    efstack.push(2);
    efstack.push(3);
    efstack.push(4);
    efstack.push(5);
    printContainer(efstack);

    std::cout << "Found: " << *easyfind(efstack, 3) << std::endl;

    std::cout << "\n--- addRange from MutantStack to Span ---" << std::endl;
    Span sp(10);
    sp.addRange(efstack.begin(), efstack.end());
    std::cout << "Span from MutantStack: " << sp << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    
	return 0;
}
