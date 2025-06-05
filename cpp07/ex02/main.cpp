/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:54:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/05 20:05:27 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(void) {
    std::cout << "--- Empty array ---" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n--- Int array test ---" << std::endl;
	Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        
    std::cout << "\n--- String array test ---" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "Array";
	strings[2] = "Template";
	for (unsigned int i = 0; i < strings.size(); ++i)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

    std::cout << "\n--- Copy test ---" << std::endl;
	Array<std::string> copy = strings;
	copy[1] = "Copied!";
	std::cout << "Original: " << strings[1] << std::endl;
	std::cout << "Copy    : " << copy[1] << std::endl;

    std::cout << "\n--- Out-of-bounds access test ---" << std::endl;
	try {
		std::cout << strings[5] << std::endl; // invalid index
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

    return 0; 
}