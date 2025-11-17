/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:23:36 by natferna          #+#    #+#             */
/*   Updated: 2025/11/06 21:12:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat high("Alice", 1);
        std::cout << high << std::endl;
        high.incrementGrade();
    }
    
    catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat low("Bob", 150);
        std::cout << low << std::endl;
        low.decrementGrade();
    }

    catch(const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad("Charlie", 200);
    }
    
    catch(const std::exception& e) {
        std::cout << "Exception caught: Charlie failed " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat bad2("Daniel", -10);
    }
    
    catch(const std::exception& e) {
        std::cout << "Exception caught: Daniel failed " << e.what() << std::endl;
    }
    
    return 0;
}