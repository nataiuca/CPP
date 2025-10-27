#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // para roundf

class Fixed {
private:
    int                 _rawBits;          // valor entero que almacena el número fijo
    static const int    _fractionalBits = 8;       // número de bits fraccionales (siempre 8)

public:
    // Constructores canonicos
    Fixed();                                // constructor por defecto
    Fixed(const Fixed& other);              // constructor de copia
    Fixed& operator=(const Fixed& other);   // operador de asignación
    ~Fixed();                               // destructor

    // Nuevos constructores (ex01)
    Fixed(const int n);                     // constructor desde int
    Fixed(const float f);                   // constructor desde float

    // Métodos de conversión
    float toFloat(void) const;
    int   toInt(void) const;

    // Métodos get/set del ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

// Sobrecarga del operador << (fuera de la clase)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
