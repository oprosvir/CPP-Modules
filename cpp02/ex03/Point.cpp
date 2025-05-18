/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:39:06 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/19 00:22:54 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}
Point::~Point() {}

Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }