/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:26:14 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/15 16:47:13 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>    // roundf

class Fixed {
    private:
        int _rawBits;
        static const int _fractionalBits = 8;    // always 8
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        Fixed(const int val);           // new
        Fixed(const float val);         // new
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;      // new
        int toInt(void) const;          // new
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif