/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:06:23 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:09:03 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating MateriaSource ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Creating Characters ===" << std::endl;
    ICharacter* alice = new Character("Alice");
    ICharacter* bob   = new Character("Bob");

    std::cout << "\n=== Equipping Materias ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    alice->equip(tmp);
    tmp = src->createMateria("cure");
    alice->equip(tmp);

    std::cout << "\n=== Using Materias ===" << std::endl;
    alice->use(0, *bob); // Ice
    alice->use(1, *bob); // Cure

    std::cout << "\n=== Unequip test ===" << std::endl;
    alice->unequip(0);   // Unequip Ice
    alice->use(0, *bob); // Should do nothing
    alice->use(1, *bob); // Cure still works

    std::cout << "\n=== Deep copy Character ===" << std::endl;
    Character* copyAlice = new Character(*(Character*)alice); // Deep copy
    copyAlice->use(0, *bob); // Index 0 was nullptr, does nothing
    copyAlice->use(1, *bob); // Cure still works

    std::cout << "\n=== Changing original and checking copy ===" << std::endl;
    tmp = src->createMateria("ice");
    alice->equip(tmp); // Re-equip Ice
    alice->use(0, *bob); // Ice works on original
    copyAlice->use(0, *bob); // Should still be nullptr, deep copy intact

    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete copyAlice;
    delete bob;
    delete alice;
    delete src;

    return 0;
}
