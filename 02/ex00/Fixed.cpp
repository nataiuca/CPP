/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:53:08 by natferna          #+#    #+#             */
/*   Updated: 2025/10/27 12:32:38 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include "Fixed.hpp"


Fixed::Fixed(): _fixedPointValue(0) {
    std::cout << "Default constructor called" <<  std::endl; 
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment called" << std::endl;
    if (this != &other)
       _fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}