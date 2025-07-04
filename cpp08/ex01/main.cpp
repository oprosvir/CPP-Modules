/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:50:59 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/09 23:03:48 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main(void) {
    std::cout << "--- Basic span ---" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Span: " << sp << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // -> 2
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // -> 14

    std::cout << "\n--- Exception on overflow ---" << std::endl;
    try {
		sp.addNumber(99);
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
    
    std::cout << "\n--- Copy constructor test ---" << std::endl;
    Span original(4);
    original.addNumber(10);
	original.addNumber(20);
	original.addNumber(30);
    
    Span copy(original);
    
    std::cout << "Before modification:\n";
    std::cout << "    Original: " << original << std::endl;
    std::cout << "    Copy:     " << copy << std::endl;
    
    original.addNumber(40);
    
    std::cout << "After modification of original:\n";
    std::cout << "    Original: " << original << std::endl;
	std::cout << "    Copy:     " << copy << std::endl;
    
    std::cout << "\n--- Assignment operator test ---" << std::endl;
    Span assigned;
    assigned = sp;
    std::cout << "Assigned: " << assigned << std::endl;

    std::cout << "\n--- Manual add test (10000 elements) ---" << std::endl;
    Span big(10000);

    for (int i = 0; i < 10000; ++i)
        big.addNumber(i * 3);
    
    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest span: " << big.longestSpan() << std::endl;
    //std::cout << big << std::endl;

    std::cout << "\n--- Equal elements test ---" << std::endl;

    Span fet(2);
    fet.addNumber(2);
    fet.addNumber(2);
    std::cout << "Span: " << fet << std::endl;
    std::cout << "Shortest span: " << fet.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << fet.longestSpan() << std::endl;

    std::cout << "\n--- Exception with too few elements ---" << std::endl;

    Span tiny(1);
    tiny.addNumber(42);

    std::cout << "Span: " << tiny << std::endl;
    try {
        std::cout << "Shortest span: " << tiny.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Longest span: " << tiny.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- addRange test ---" << std::endl;
    Span srange(10);
    std::vector<int> batch;
    for (int i = 0; i < 7; ++i)
        batch.push_back(i * 10);

    std::cout << "Before addRange: " << srange << std::endl;
    srange.addRange(batch.begin(), batch.end());
    std::cout << "After addRange:  " << srange << std::endl;

    std::cout << "\n--- addRange overflow test ---" << std::endl;
    try {
        srange.addRange(batch.begin(), batch.end()); // > 10
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- addRange from std::list ---" << std::endl;
    Span slist(10);
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    slist.addRange(l.begin(), l.end());
    std::cout << "After list add:   " << slist << std::endl;

    std::cout << "\n--- addRange from array ---" << std::endl;
    Span sarray(10);
    int arr[] = {100, 200, 300};
    sarray.addRange(arr, arr + 3);
    std::cout << "After array add:  " << sarray << std::endl;

    return 0;
}
