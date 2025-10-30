/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:06:04 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:06:06 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        materias[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < 4; ++i)
        materias[i] = other.materias[i] ? other.materias[i]->clone() : nullptr;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete materias[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete materias[i];
            materias[i] = other.materias[i] ? other.materias[i]->clone() : nullptr;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return nullptr;
}
