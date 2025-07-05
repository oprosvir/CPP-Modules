/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:12:33 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/05 14:43:32 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    (void)argv;
    if (argc < 2)
    {
        std::cerr << "Error: no input provided." << std::endl;
        return 1;
    }

    // Process the input arguments and perform the merge operation
    // This is a placeholder for the actual implementation
    std::cout << "Processing input..." << std::endl;

    // Example of how to use the PmergeMe class (to be implemented)
    // PmergeMe pm;
    // pm.processInput(argc, argv);

    return 0;
}