/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:05:27 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/11 09:49:31 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl harl;

    harl.complain("DEBUG");
    std::cout << std::endl;
    
    harl.complain("INFO");
    std::cout << std::endl;
    
    harl.complain("WARNING");
    std::cout << std::endl;
    
    harl.complain("ERROR");
    std::cout << std::endl;
    
    harl.complain("COOKIES");
    
    return 0;
}