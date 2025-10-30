/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:40:06 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 13:44:14 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating array of Animals ===" << std::endl;
    Animal* animals[4];

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Testing makeSound ===" << std::endl;
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Setting ideas ===" << std::endl;
    dynamic_cast<Dog*>(animals[0])->setIdea(0, "Fetch the ball!");
    dynamic_cast<Cat*>(animals[1])->setIdea(0, "Climb the tree!");
    std::cout << "Dog idea: " << dynamic_cast<Dog*>(animals[0])->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << dynamic_cast<Cat*>(animals[1])->getIdea(0) << std::endl;

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog* dogOriginal = new Dog();
    dogOriginal->setIdea(0, "Fetch the ball!");
    Dog* dogCopy = new Dog(*dogOriginal); // copy constructor
    std::cout << "DogCopy idea before change: " << dogCopy->getIdea(0) << std::endl;
    dogCopy->setIdea(0, "Sleep all day");
    std::cout << "Dog original idea: " << dogOriginal->getIdea(0) << std::endl;
    std::cout << "DogCopy idea after change: " << dogCopy->getIdea(0) << std::endl;

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];
    delete dogOriginal;
    delete dogCopy;

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
