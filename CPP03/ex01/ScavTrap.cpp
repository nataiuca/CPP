/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:18:47 by natferna          #+#    #+#             */
/*   Updated: 2025/10/28 23:34:11 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// Constructor por defecto
ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Constructor con nombre
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called for " << name << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Operador de asignación
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

// Sobrescribimos attack()
void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap <" << _name << "> cannot attack, it's destroyed." << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        static bool warned = false; // avisar solo una vez
        if (!warned) {
            std::cout << "ScavTrap <" << _name << "> has no energy left!" << std::endl;
            warned = true;
        }
        return;
    }
    _energyPoints -= 1;
    std::cout << "ScavTrap <" << _name << "> attacks <" << target << "> fiercely, causing "
              << _attackDamage << " damage! (EP left: " << _energyPoints << ")" << std::endl;
}

// Acción extra
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}
