/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:16:45 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 00:17:18 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor por defecto
FragTrap::FragTrap(void)
: ClapTrap("FragTrap")
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

// Constructor con nombre
FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << "FragTrap name constructor called for <" << name << ">" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

// Constructor de copia
FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

// Operador de asignación
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor virtual
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for <" << _name << ">" << std::endl;
}

// Nueva acción
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap <" << _name << "> requests a positive high five! 🙌" << std::endl;
}
