/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:21:29 by natferna          #+#    #+#             */
/*   Updated: 2025/11/23 12:41:34 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // parse input: returns 0 on success, 1 on error (prints "Error")
    int parseInput(int argc, char **argv);

    // Run sorting for both containers and measure times
    void sortContainers();

    // getters
    const std::vector<unsigned int> &getVector() const;
    const std::deque<unsigned int> &getDeque() const;
    double getVectorTime() const;
    double getDequeTime() const;

private:
    std::vector<unsigned int> _vec;
    std::deque<unsigned int> _deq;
    double _vecTime;
    double _deqTime;

    // Ford–Johnson / Merge-Insertion implementations
    void mergeInsertVector(std::vector<unsigned int> &v);
    void mergeInsertDeque(std::deque<unsigned int> &d);

    // helpers for vector
    void binaryInsertVector(std::vector<unsigned int> &arr, unsigned int val, size_t right);
    void jacobsthalOrderInsertVector(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &pending);

    // helpers for deque
    void binaryInsertDeque(std::deque<unsigned int> &arr, unsigned int val, size_t right);
    void jacobsthalOrderInsertDeque(std::deque<unsigned int> &mainChain, std::deque<unsigned int> &pending);
};

// printing helpers (used by main)
void printBefore(const std::vector<unsigned int> &v);
void printAfter(const std::deque<unsigned int> &d);

#endif
