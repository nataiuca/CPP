/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:40:06 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 09:57:00 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Polymorphism ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    cat->makeSound(); // Cat sound
    dog->makeSound(); // Dog sound
    meta->makeSound(); // Generic sound

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Wrong Polymorphism ===" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // Will print WrongAnimal sound
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Getter/Setter Test ===" << std::endl;

    Dog myDog;
    myDog.setType("Husky");
    std::cout << "Dog type: " << myDog.getType() << std::endl;
    myDog.makeSound();

    return 0;
}
