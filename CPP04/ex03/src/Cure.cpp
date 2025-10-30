/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:04:39 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:05:00 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const & other) : AMateria(other) {}
Cure::~Cure() {}

Cure & Cure::operator=(Cure const & other)
{
    AMateria::operator=(other);
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
