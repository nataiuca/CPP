/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:21:24 by natferna          #+#    #+#             */
/*   Updated: 2025/11/23 12:41:51 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <climits>
#include <vector>

// ---------------- Canonical ----------------
PmergeMe::PmergeMe() : _vec(), _deq(), _vecTime(0.0), _deqTime(0.0) {}
PmergeMe::PmergeMe(const PmergeMe &other)
    : _vec(other._vec), _deq(other._deq), _vecTime(other._vecTime), _deqTime(other._deqTime) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// ---------------- time helper ----------------
static double time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// ---------------- input parsing ----------------
// Strict validation: only digits, >0, no overflow to unsigned int.
// On any invalid argument prints "Error" on stderr and returns 1.
int PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        const char *s = argv[i];
        if (s == NULL || s[0] == '\0') {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        // ensure every char is digit
        for (size_t j = 0; s[j] != '\0'; ++j) {
            if (s[j] < '0' || s[j] > '9') {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
        // convert and validate >0 and within unsigned int
        unsigned long val = strtoul(s, NULL, 10);
        if (val == 0 || val > UINT_MAX) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        unsigned int v = static_cast<unsigned int>(val);
        _vec.push_back(v);
        _deq.push_back(v);
    }
    return 0;
}

// ---------------- print helpers ----------------
// For small sequences (<=10) print concatenated without spaces.
// For large sequences (>10) print first 5 separated and " [...]" as in subject.

void printBefore(const std::vector<unsigned int> &v) {
    std::cout << "Before:  ";
    size_t n = v.size();
    if (n <= 10) {
        for (size_t i = 0; i < n; ++i) std::cout << v[i];
    } else {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << v[i];
            if (i + 1 < 5) std::cout << " ";
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;
}

void printAfter(const std::deque<unsigned int> &d) {
    std::cout << "After:   ";
    size_t n = d.size();
    if (n <= 10) {
        for (size_t i = 0; i < n; ++i) std::cout << d[i];
    } else {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << d[i];
            if (i + 1 < 5) std::cout << " ";
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;
}

// ---------------- Jacobsthal indices ----------------
// Generate the sequence t: 1,3,5,11,21,... until >= m
static void generate_jacobsthal_indices(std::vector<size_t> &t, size_t m) {
    t.clear();
    if (m == 0) return;
    t.push_back(1);
    size_t k = 2;
    while (t.back() < m) {
        size_t pow2 = 1;
        for (size_t i = 0; i < k; ++i) pow2 *= 2;
        size_t tk = pow2 - t.back();
        t.push_back(tk);
        ++k;
        if (k > 31) break; // safety
    }
}

// ---------------- binary insert (vector) ----------------
// insert val into arr[0..right) keeping ascending order
void PmergeMe::binaryInsertVector(std::vector<unsigned int> &arr, unsigned int val, size_t right) {
    size_t left = 0;
    size_t r = right;
    while (left < r) {
        size_t mid = left + (r - left) / 2;
        if (arr[mid] < val) left = mid + 1;
        else r = mid;
    }
    arr.insert(arr.begin() + left, val);
}

// ---------------- binary insert (deque) ----------------
void PmergeMe::binaryInsertDeque(std::deque<unsigned int> &arr, unsigned int val, size_t right) {
    size_t left = 0;
    size_t r = right;
    while (left < r) {
        size_t mid = left + (r - left) / 2;
        if (arr[mid] < val) left = mid + 1;
        else r = mid;
    }
    arr.insert(arr.begin() + left, val);
}

// ---------------- jacobsthal insertion for vector ----------------
void PmergeMe::jacobsthalOrderInsertVector(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &pending) {
    size_t m = pending.size();
    if (m == 0) return;
    std::vector<size_t> t;
    generate_jacobsthal_indices(t, m);
    size_t prev = 0;
    for (size_t k = 0; k < t.size(); ++k) {
        size_t tk = t[k];
        size_t start = prev + 1;
        size_t end = (tk <= m ? tk : m);
        if (start <= end) {
            for (size_t idx = end; idx >= start; --idx) {
                unsigned int val = pending[idx - 1];
                size_t bound = (2 * idx - 1);
                if (bound > mainChain.size()) bound = mainChain.size();
                binaryInsertVector(mainChain, val, bound);
                if (idx == start) break;
            }
        }
        prev = tk;
        if (prev >= m) break;
    }
    if (t.empty() || t.back() < m) {
        size_t start = (t.empty() ? 1 : t.back() + 1);
        for (size_t idx = m; idx >= start; --idx) {
            unsigned int val = pending[idx - 1];
            size_t bound = (2 * idx - 1);
            if (bound > mainChain.size()) bound = mainChain.size();
            binaryInsertVector(mainChain, val, bound);
            if (idx == start) break;
        }
    }
}

// ---------------- jacobsthal insertion for deque ----------------
void PmergeMe::jacobsthalOrderInsertDeque(std::deque<unsigned int> &mainChain, std::deque<unsigned int> &pending) {
    size_t m = pending.size();
    if (m == 0) return;
    std::vector<size_t> t;
    generate_jacobsthal_indices(t, m);
    size_t prev = 0;
    for (size_t k = 0; k < t.size(); ++k) {
        size_t tk = t[k];
        size_t start = prev + 1;
        size_t end = (tk <= m ? tk : m);
        if (start <= end) {
            for (size_t idx = end; idx >= start; --idx) {
                unsigned int val = pending[idx - 1];
                size_t bound = (2 * idx - 1);
                if (bound > mainChain.size()) bound = mainChain.size();
                binaryInsertDeque(mainChain, val, bound);
                if (idx == start) break;
            }
        }
        prev = tk;
        if (prev >= m) break;
    }
    if (t.empty() || t.back() < m) {
        size_t start = (t.empty() ? 1 : t.back() + 1);
        for (size_t idx = m; idx >= start; --idx) {
            unsigned int val = pending[idx - 1];
            size_t bound = (2 * idx - 1);
            if (bound > mainChain.size()) bound = mainChain.size();
            binaryInsertDeque(mainChain, val, bound);
            if (idx == start) break;
        }
    }
}

// ---------------- Merge-Insertion for vector ----------------
void PmergeMe::mergeInsertVector(std::vector<unsigned int> &v) {
    size_t n = v.size();
    if (n <= 1) return;

    std::vector<unsigned int> bigs;
    std::vector<unsigned int> smalls;
    bool has_leftover = (n % 2 == 1);
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        unsigned int a = v[i];
        unsigned int b = v[i + 1];
        if (a < b) {
            smalls.push_back(a);
            bigs.push_back(b);
        } else {
            smalls.push_back(b);
            bigs.push_back(a);
        }
    }
    unsigned int leftover = 0;
    if (has_leftover) leftover = v[n - 1];

    // recursively sort bigs
    mergeInsertVector(bigs);

    // mainChain = bigs (sorted)
    std::vector<unsigned int> mainChain = bigs;

    // insert smalls in Jacobsthal order
    jacobsthalOrderInsertVector(mainChain, smalls);

    // insert leftover if any
    if (has_leftover) binaryInsertVector(mainChain, leftover, mainChain.size());

    // replace
    v = mainChain;
}

// ---------------- Merge-Insertion for deque ----------------
void PmergeMe::mergeInsertDeque(std::deque<unsigned int> &d) {
    size_t n = d.size();
    if (n <= 1) return;

    std::deque<unsigned int> bigs;
    std::deque<unsigned int> smalls;
    bool has_leftover = (n % 2 == 1);
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        unsigned int a = d[i];
        unsigned int b = d[i + 1];
        if (a < b) {
            smalls.push_back(a);
            bigs.push_back(b);
        } else {
            smalls.push_back(b);
            bigs.push_back(a);
        }
    }
    unsigned int leftover = 0;
    if (has_leftover) leftover = d[n - 1];

    // recursive on bigs
    mergeInsertDeque(bigs);

    // mainChain = bigs (sorted)
    std::deque<unsigned int> mainChain = bigs;

    // insert smalls
    jacobsthalOrderInsertDeque(mainChain, smalls);

    if (has_leftover) binaryInsertDeque(mainChain, leftover, mainChain.size());

    d = mainChain;
}

// ---------------- sortContainers ----------------
void PmergeMe::sortContainers() {
    double t0 = time_us();
    mergeInsertVector(_vec);
    double t1 = time_us();
    _vecTime = t1 - t0;

    t0 = time_us();
    mergeInsertDeque(_deq);
    t1 = time_us();
    _deqTime = t1 - t0;
}

// ---------------- getters ----------------
const std::vector<unsigned int> &PmergeMe::getVector() const { return _vec; }
const std::deque<unsigned int> &PmergeMe::getDeque() const { return _deq; }
double PmergeMe::getVectorTime() const { return _vecTime; }
double PmergeMe::getDequeTime() const { return _deqTime; }
