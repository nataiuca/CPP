/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:02:08 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 22:02:08 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <exception>
# include <limits>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    // Forma canónica
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // Métodos principales
    void addNumber(int n);

    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::overflow_error("Span is full");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const { return _numbers.size(); }
    unsigned int capacity() const { return _maxSize; }
};

#endif