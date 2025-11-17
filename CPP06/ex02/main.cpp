/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:53:23 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:53:23 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time
#include "Base.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL))); // inicializa semilla aleatoria

    Base* obj = generate();

    std::cout << "Identifying using pointer: ";
    identify(obj);

    std::cout << "Identifying using reference: ";
    identify(*obj);

    delete obj;
    return 0;
}
