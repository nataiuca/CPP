/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:54:15 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 00:54:29 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor por defecto
DiamondTrap::DiamondTrap(void)
: ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap()
{
	_name = "DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;   // HP de FragTrap
	_energyPoints = ScavTrap::_energyPoints; // EP de ScavTrap
	_attackDamage = FragTrap::_attackDamage; // AD de FragTrap
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Constructor con nombre
DiamondTrap::DiamondTrap(std::string const & name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap name constructor called for <" << _name << ">" << std::endl;
}

// Constructor de copia
DiamondTrap::DiamondTrap(DiamondTrap const & other)
: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

// Operador de asignación
DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for <" << _name << ">" << std::endl;
}

// Sobrescribimos attack() → usa ScavTrap::attack()
void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

// Acción exclusiva
void DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap <" << _name
			  << "> and my ClapTrap name is <" << ClapTrap::_name << ">" << std::endl;
}
