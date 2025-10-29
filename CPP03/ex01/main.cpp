/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:08:04 by natferna          #+#    #+#             */
/*   Updated: 2025/10/28 23:48:38 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // 1️⃣ Crear un ScavTrap
    ScavTrap jack("Jack");

    // 2️⃣ Prueba de ataque
    jack.attack("Psycho");       // debe imprimir mensaje de ScavTrap
    jack.takeDamage(30);         // heredado de ClapTrap
    jack.beRepaired(20);         // heredado de ClapTrap

    // 3️⃣ Activar Guard Gate
    jack.guardGate();            // mensaje de Gate Keeper mode

    // 4️⃣ Ataques hasta quedarse sin energía
    while (jack.getEnergyPoints() > 0)
        jack.attack("Target");

    // 5️⃣ Intento de ataque sin energía
    jack.attack("Target");       // debe imprimir "has no energy left!"

    // 6️⃣ Destructor llamado automáticamente al salir del scope
    return 0;
}
