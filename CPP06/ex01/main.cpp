/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:35:14 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:35:14 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarSerializer.hpp"

int main() {
    Data *p = new Data("Test", 42);

    std::cout << "Original pointer: " << p << std::endl;

    uintptr_t raw = Serializer::serialize(p);
    std::cout << "Serialized: " << raw << std::endl;

    Data *newPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    std::cout << "Name: " << newPtr->getName() << std::endl;
    std::cout << "Value: " << newPtr->getValue() << std::endl;

    delete p;
}
