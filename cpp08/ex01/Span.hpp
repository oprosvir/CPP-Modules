/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:51:20 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/08 23:16:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

class Span {
public:
    Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
    
    const std::vector<int>& getData() const;
    unsigned int getMaxSize() const;

private:
	unsigned int _maxSize;
	std::vector<int> _data;
};

std::ostream& operator<<(std::ostream& o, const Span& span);

#endif