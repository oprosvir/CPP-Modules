/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:54:39 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/16 18:18:00 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {    
    std::cout << "\033[1;32m--- Subject main ---\033[0m" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    std::cout << "\n\033[1;32m--- Comparison operators ---\033[0m" << std::endl;
    Fixed c(10);
    Fixed d(10.1f);
    std::cout << std::boolalpha;
    std::cout << "c:         " << c << std::endl;
    std::cout << "d:         " << d << std::endl;

    std::cout << "c < d:     " << (c < d) << std::endl;
    std::cout << "c <= d:    " << (c <= d) << std::endl;
    std::cout << "c > d:     " << (c > d) << std::endl;
    std::cout << "c >= d:    " << (c >= d) << std::endl;
    std::cout << "c == d:    " << (c == d) << std::endl;
    std::cout << "c != d:    " << (c != d) << std::endl;

    std::cout << "\n\033[1;32m--- Arithmetic operators ---\033[0m" << std::endl;
    Fixed x(10);
    Fixed y(-2.5f);
    std::cout << "x:        " << x << std::endl;
    std::cout << "y:        " << y << std::endl;

    std::cout << "x + y:    " << (x + y) << std::endl;
    std::cout << "x - y:    " << (x - y) << std::endl;
    std::cout << "x * y:    " <<  (x * y) << std::endl;
    std::cout << "x / y:    " << (x / y) << std::endl;

    std::cout << "\n\033[1;32m--- Increment / Decrement operators ---\033[0m" << std::endl;
    Fixed z;
    std::cout << "Initial z         " << z << std::endl;
    std::cout << "++z (prefix):     " << ++z << std::endl;  // 0.00390625 step
    std::cout << "z after ++z:      " << z << std::endl;
    std::cout << "z++ (postfix):    " << z++ << std::endl;
    std::cout << "z after z++:      " << z << std::endl;
    std::cout << "--z (prefix):     " << --z << std::endl;
    std::cout << "z after --z:      " << z << std::endl;
    std::cout << "z-- (postfix):    " << z-- << std::endl;
    std::cout << "z after z--:      " << z << std::endl;
    
    std::cout << "\n\033[1;32m--- Min / Max tests ---\033[0m" << std::endl;

    Fixed m1(3.5f);
    Fixed m2(4.2f);
    const Fixed cm1(8.8f);
    const Fixed cm2(8.81f);

    std::cout << "m1:       " << m1 << std::endl;
    std::cout << "m2:       " << m2 << std::endl;
    std::cout << "min(m1, m2): " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2): " << Fixed::max(m1, m2) << std::endl;

    std::cout << "cm1:      " << cm1 << std::endl;
    std::cout << "cm2:      " << cm2 << std::endl;
    std::cout << "min(cm1, cm2): " << Fixed::min(cm1, cm2) << std::endl;
    std::cout << "max(cm1, cm2): " << Fixed::max(cm1, cm2) << std::endl;

    std::cout << "Mixed min(m1, cm1): " << Fixed::min(m1, cm1) << std::endl;
    std::cout << "Mixed max(cm2, m2): " << Fixed::max(cm2, m2) << std::endl;
    
    return 0;
}