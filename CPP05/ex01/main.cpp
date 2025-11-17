/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:55:22 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 22:55:22 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat boss("Boss", 1);

        Form contract("Contract", 30, 10);
        Form secret("Secret paper", 1, 1);

        std::cout << contract << std::endl;
        std::cout << secret   << std::endl;

        bob.signForm(contract);     // debe fallar
        boss.signForm(contract);    // lo firma

        boss.signForm(secret);      // lo firma
        bob.signForm(secret);       // debe fallar

        std::cout << contract << std::endl;
        std::cout << secret   << std::endl;
    }
    catch(const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
