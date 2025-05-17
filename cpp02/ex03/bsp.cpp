/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:39:35 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/16 19:08:35 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
    return (a.getX() * (b.getY() - c.getY()) +
            b.getX() * (c.getY() - a.getY()) +
            c.getX() * (a.getY() - b.getY())) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed fullArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    // check if point is inside and not on the edge or vertex
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return (fullArea == (area1 + area2 + area3));
}
