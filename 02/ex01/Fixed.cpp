/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:25:31 by natferna          #+#    #+#             */
/*   Updated: 2025/10/27 12:45:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
