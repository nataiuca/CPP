/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:40:06 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 13:07:43 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Creating array of Animals ===" << std::endl;

    const Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "Chase the mailman!");

    Dog dog2 = dog1; // copy constructor (deep copy)
    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "Sleep all day");
    std::cout << "After modification:\n";
    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
