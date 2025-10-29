/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:56:05 by natferna          #+#    #+#             */
/*   Updated: 2025/10/28 22:56:06 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("C-3PO");
    ClapTrap b;                    // default named ClapTrap
    ClapTrap c(a);                 // copy

    a.attack("R2-D2");
    a.takeDamage(3);
    a.beRepaired(5);

    // exhaust energy
    for (int i = 0; i < 12; ++i)
        a.attack("R2-D2");

    b.takeDamage(12);
    b.beRepaired(3); // cannot, destroyed

    c = a; // assignment
    c.attack("Psycho");

    return 0;
}
