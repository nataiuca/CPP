/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:30:05 by natferna          #+#    #+#             */
/*   Updated: 2025/11/17 01:30:05 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm> // <- necesario para std::sort
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

int PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (s.empty()) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] < '0' || s[j] > '9') {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
        unsigned int val = static_cast<unsigned int>(atoi(s.c_str()));
        _vector.push_back(val);
        _deque.push_back(val);
    }
    return 0;
}

static double getTimeMicro() {
    timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000.0 + start.tv_usec;
}

void PmergeMe::sortContainers() {
    double start = getTimeMicro();
    std::sort(_vector.begin(), _vector.end());
    double end = getTimeMicro();
    _vectorTime = end - start;

    start = getTimeMicro();
    std::sort(_deque.begin(), _deque.end());
    end = getTimeMicro();
    _dequeTime = end - start;
}

void printContainer(const std::vector<unsigned int>& c) {
    std::cout << "Before:  ";
    size_t n = c.size();
    for (size_t i = 0; i < n && i < 5; ++i)
        std::cout << c[i] << " ";
    if (n > 5) std::cout << "[...]";
    std::cout << std::endl;
}

void printContainer(const std::deque<unsigned int>& c) {
    std::cout << "After:   ";
    size_t n = c.size();
    for (size_t i = 0; i < n && i < 5; ++i)
        std::cout << c[i] << " ";
    if (n > 5) std::cout << "[...]";
    std::cout << std::endl;
}
