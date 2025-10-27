/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:35:25 by natferna          #+#    #+#             */
/*   Updated: 2025/10/22 16:00:15 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _rawBits(0) {
}

Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _rawBits != other._rawBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

// Min/Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Getters/Setters
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
