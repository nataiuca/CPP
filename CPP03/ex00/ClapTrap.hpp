/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:55:53 by natferna          #+#    #+#             */
/*   Updated: 2025/10/28 22:55:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap(void);                       // default constructor
    ClapTrap(std::string _name);   // name constructor
    ClapTrap(const ClapTrap &other);     // copy constructor
    ClapTrap& operator=(const ClapTrap &other); // copy assignment
    ~ClapTrap(void);                      // destructor

    // Actions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters (útiles para tests)
    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
};

#endif
