/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:05:42 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:05:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = nullptr;
}

Character::Character(Character const & other) : name(other.name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

Character & Character::operator=(Character const & other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
        }
    }
    return *this;
}

std::string const & Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter & target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
