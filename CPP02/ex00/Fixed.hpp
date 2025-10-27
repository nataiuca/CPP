#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;          // valor entero que almacena el número fijo
    static const int    _fractionalBits = 8;       // número de bits fraccionales (siempre 8)

public:
    // Constructores canonicos
    Fixed();                                // constructor por defecto
    Fixed(const Fixed& other);              // constructor de copia
    Fixed& operator=(const Fixed& other);   // operador de asignación
    ~Fixed();                               // destructor

    // Métodos get/set del ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
