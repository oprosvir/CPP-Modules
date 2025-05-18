/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:52:23 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/19 00:36:28 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2);
    Point outside(11, 5); // outside "false"
    Point edge(0, 5);   // on edge "false"
    Point vertex(0, 0); // vertex "false"
    

    std::cout << std::boolalpha;
    std::cout << "Point inside:  " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;

    return 0;
}