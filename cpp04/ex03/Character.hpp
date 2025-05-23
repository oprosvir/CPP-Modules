/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:23:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 10:05:21 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string _name;
    AMateria* _inventory[4];
    AMateria* _dropped[42];
    int _dropCount;
public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
    
    Character(std::string const & name);
    std::string const & getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
