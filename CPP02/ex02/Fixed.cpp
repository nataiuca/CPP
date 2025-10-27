#include "Fixed.hpp"

// --- Constructores y destructor ---
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n) {
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

// --- Métodos de conversión ---
float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// --- Getters y setters ---
int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// --- Operadores de comparación ---
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// --- Operadores aritméticos ---
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)this->_fixedPointValue * (long)other._fixedPointValue;
    result.setRawBits((int)(tmp >> _fractionalBits)); // ajustar bits fraccionales
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: division by zero!" << std::endl;
        return result;
    }
    long tmp = ((long)this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
    result.setRawBits((int)tmp);
    return result;
}

// --- Incrementos y decrementos ---
Fixed& Fixed::operator++() { // pre
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) { // post
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() { // pre
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) { // post
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

// --- min/max ---
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

// --- Operador <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
