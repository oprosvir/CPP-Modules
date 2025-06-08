/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:51:14 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/08 23:55:54 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int N) : _maxSize(N) {}
Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {}
Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_data.push_back(number);
}

int Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");

	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());
	return maxVal - minVal;
}

const std::vector<int>& Span::getData() const {
	return _data;
}

unsigned int Span::getMaxSize() const {
	return _maxSize;
}

std::ostream& operator<<(std::ostream& o, const Span& span) {
	const std::vector<int>& data = span.getData();
	o << "[ ";
	for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
		o << *it << " ";
	o << "] (size: " << data.size() << "/" << span.getMaxSize() << ")";
	return o;
}
