/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:02:16 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 22:02:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructores
Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

// Métodos principales
void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}
