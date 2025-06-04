/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:34:26 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/04 22:50:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T* array, int length, void (*func)(T const&)) {
	if (!array || !func || length < 0)
		return;
	for (int i = 0; i < length; ++i)
		func(array[i]);
}

#endif