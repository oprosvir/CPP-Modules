/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:54:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/07 12:04:54 by oprosvir         ###   ########.fr       */
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
	std::cout << "Before initialization:\n";
	std::cout << numbers;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;
	std::cout << "After initialization:\n";
	std::cout << numbers;

	std::cout << "\n--- Float array test ---" << std::endl;
	Array<float> floats(4);
	std::cout << "Before initialization:\n";
	std::cout << floats;
	for (unsigned int i = 0; i < floats.size(); ++i)
		floats[i] = i + 0.5f;
	std::cout << "After initialization:\n";
	std::cout << floats;

	std::cout << "\n--- Bool array test ---" << std::endl;
	const Array<bool> flags(2);
	std::cout << "Before initialization:\n";
	std::cout << flags;
        
    std::cout << "\n--- String array test ---" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "Array";
	strings[2] = "Template";
	std::cout << strings;

    std::cout << "\n--- Copy test ---" << std::endl;
	Array<std::string> copy = strings;
	copy[1] = "Copied!";
	std::cout << "Original: " << strings[1] << std::endl;
	std::cout << "Copy    : " << copy[1] << std::endl;

	std::cout << "\n--- Assignment operator test ---" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	std::cout << assigned;

    std::cout << "\n--- Out-of-bounds access test ---" << std::endl;
	try {
		std::cout << strings[5] << std::endl; // invalid index
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

    return 0; 
}