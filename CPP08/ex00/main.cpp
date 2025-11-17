/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:36:08 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 21:36:08 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // ====================
    // TEST CON VECTOR
    // ====================
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout << "Testing with std::vector<int>:" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // ====================
    // TEST CON LIST
    // ====================
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::cout << "\nTesting with std::list<int>:" << std::endl;
    try {
        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
