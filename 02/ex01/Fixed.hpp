/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:25:10 by natferna          #+#    #+#             */
/*   Updated: 2025/10/27 12:44:21 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                          
    Fixed(const int n);         
    Fixed(const float f);        
    Fixed(const Fixed& other);       
    ~Fixed();                        

    Fixed& operator=(const Fixed& other); 

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
