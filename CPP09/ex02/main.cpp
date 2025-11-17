/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:30:09 by natferna          #+#    #+#             */
/*   Updated: 2025/11/17 01:30:09 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe pm;

    if (pm.parseInput(argc, argv) != 0)
        return 1;

    printContainer(pm.getVector());
    pm.sortContainers();
    printContainer(pm.getDeque());

    size_t n = pm.getVector().size();
    std::cout << "Time to process a range of " << n 
              << " elements with std::vector : " << pm.getVectorTime() << " us" << std::endl;
    std::cout << "Time to process a range of " << n 
              << " elements with std::deque  : " << pm.getDequeTime() << " us" << std::endl;

    return 0;
}
