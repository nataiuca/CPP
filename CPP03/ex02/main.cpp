/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:17:28 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 00:17:29 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap frag("Fraggy");
	ScavTrap scav("Scavvy");

	std::cout << std::endl;

	frag.attack("Bandit");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << std::endl;

	scav.attack("Vault Hunter");
	scav.guardGate();

	std::cout << std::endl;

	return 0;
}
