#include "Fixed.hpp"

// --- Constructores y destructor ---
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // reutilizamos el operador de asignación
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits= other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --- Nuevos constructores ---
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits; // desplazamos bits para codificar parte fraccional
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fractionalBits)); // redondeamos a entero
}

// --- Métodos de conversión ---
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// --- Métodos get/set ---
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

// --- Sobrecarga del operador << ---
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
