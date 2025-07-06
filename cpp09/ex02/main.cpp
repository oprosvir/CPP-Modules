/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:12:33 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/06 23:01:18 by oprosvir         ###   ########.fr       */
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
    
    try {
        PmergeMe sorter;
        sorter.load(argc, argv);
        sorter.process();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}