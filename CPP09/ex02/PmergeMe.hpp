/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 01:30:18 by natferna          #+#    #+#             */
/*   Updated: 2025/11/17 01:30:18 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <sstream>

class PmergeMe {
private:
    std::vector<unsigned int> _vector;
    std::deque<unsigned int> _deque;
    double _vectorTime;
    double _dequeTime;

public:
    PmergeMe() : _vectorTime(0), _dequeTime(0) {}
    int parseInput(int argc, char** argv);
    void sortContainers();
    const std::vector<unsigned int>& getVector() const { return _vector; }
    const std::deque<unsigned int>& getDeque() const { return _deque; }
    double getVectorTime() const { return _vectorTime; }
    double getDequeTime() const { return _dequeTime; }
};

void printContainer(const std::vector<unsigned int>& c);
void printContainer(const std::deque<unsigned int>& c);

#endif
