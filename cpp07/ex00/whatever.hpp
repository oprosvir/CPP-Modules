/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:16:47 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/04 22:22:55 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const& min(T const& a, T const& b) {
    if (a < b)
        return a;
    return b;
}

template<typename T>
T const& max(T const& a, T const& b) {
    if (a > b)
        return a;
    return b;
}

#endif