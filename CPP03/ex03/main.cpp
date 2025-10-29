/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:17:28 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 01:02:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d("Dia");
	std::cout << std::endl;

	d.attack("Enemy");
	d.takeDamage(50);
	d.beRepaired(30);
	d.highFivesGuys();  // heredado de FragTrap
	d.guardGate();      // heredado de ScavTrap
	d.whoAmI();         // propio de DiamondTrap

	std::cout << std::endl;
	return 0;
}
