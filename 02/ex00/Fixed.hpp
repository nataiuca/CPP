/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:52:56 by natferna          #+#    #+#             */
/*   Updated: 2025/10/27 12:32:20 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed{
    private:
        int _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif