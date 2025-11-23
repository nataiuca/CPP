/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:21:33 by natferna          #+#    #+#             */
/*   Updated: 2025/11/23 12:42:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
    PmergeMe pm;
    if (pm.parseInput(argc, argv) != 0)
        return 1;

    // print before (vector)
    printBefore(pm.getVector());

    // sort both containers and measure times
    pm.sortContainers();

    // print after (deque)
    printAfter(pm.getDeque());

    // print times
    size_t n = pm.getVector().size();
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << n
              << " elements with std::vector : " << pm.getVectorTime() << " us" << std::endl;
    std::cout << "Time to process a range of " << n
              << " elements with std::deque  : " << pm.getDequeTime() << " us" << std::endl;

    return 0;
}
