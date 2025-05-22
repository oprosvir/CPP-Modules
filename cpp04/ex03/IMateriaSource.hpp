/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:23:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 01:43:03 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif