/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:38:19 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:38:19 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST ===" << std::endl;

    try {
        Bureaucrat high("HighRank", 1);
        Bureaucrat mid("MidRank", 50);
        Bureaucrat low("LowRank", 150);

        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;

        low.signForm(shrub);   // Fallará
        high.signForm(shrub);  // Firma con éxito
        mid.executeForm(shrub); // Fallará (grado insuficiente)
        high.executeForm(shrub); // Creará el archivo "garden_shrubbery"

        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        RobotomyRequestForm robo("Bender");
        high.signForm(robo);
        high.executeForm(robo); // 50% éxito

        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        PresidentialPardonForm pardon("Marvin");
        high.signForm(pardon);
        high.executeForm(pardon);

        std::cout << "\n=== END TEST ===" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}