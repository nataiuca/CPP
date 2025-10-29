/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:14:19 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 00:15:55 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ----------------- Constructors / Destructor -----------------

ClapTrap::ClapTrap(void)
: _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap <" << _name << "> default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap <" << _name << "> name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap <" << other._name << "> copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap <" << _name << "> copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap <" << _name << "> destructor called" << std::endl;
}

// ----------------- Actions -----------------

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> cannot attack, it's out of hit points." << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> has no energy to attack." << std::endl;
        return;
    }
    _energyPoints -= 1;
    std::cout << "ClapTrap <" << _name << "> attacks <" << target << ">, causing "
              << _attackDamage << " points of damage! (EP left: " << _energyPoints << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> is already at 0 HP." << std::endl;
        return;
    }
    int dmg = static_cast<int>(amount);
    _hitPoints -= dmg;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap <" << _name << "> takes " << dmg << " points of damage! (HP: " << _hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> cannot be repaired because it's destroyed." << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap <" << _name << "> has no energy to repair." << std::endl;
        return;
    }
    int heal = static_cast<int>(amount);
    _energyPoints -= 1;
    _hitPoints += heal;
    std::cout << "ClapTrap <" << _name << "> is repaired by " << heal << " points! (HP: " << _hitPoints
              << ", EP left: " << _energyPoints << ")" << std::endl;
}

// ----------------- Getters -----------------

std::string ClapTrap::getName(void) const { return _name; }
int ClapTrap::getHitPoints(void) const { return _hitPoints; }
int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }
int ClapTrap::getAttackDamage(void) const { return _attackDamage; }
