/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:03:41 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:03:42 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::AMateria(AMateria const & other) : type(other.type) {}
AMateria::~AMateria() {}
AMateria & AMateria::operator=(AMateria const & other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter & target)
{
    (void)target;
    // Default does nothing
}
