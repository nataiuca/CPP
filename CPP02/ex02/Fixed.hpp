#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    // Constructores canónicos
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Constructores de conversión
    Fixed(const int n);
    Fixed(const float f);

    // Métodos de conversión
    float toFloat(void) const;
    int   toInt(void) const;

    // Getters y setters
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // --- Operadores de comparación ---
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // --- Operadores aritméticos ---
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // --- Operadores de incremento/decremento ---
    Fixed& operator++();     // pre-incremento
    Fixed operator++(int);   // post-incremento
    Fixed& operator--();     // pre-decremento
    Fixed operator--(int);   // post-decremento

    // --- Funciones min/max ---
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// --- Operador de inserción para imprimir ---
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
