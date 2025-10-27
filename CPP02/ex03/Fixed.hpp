#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					_fixedPointValue;						// Valor del número en punto fijo
	static const int	_fractionalBits = 8;		// Número de bits fraccionales

public:
	// 🔹 Orthodox Canonical Form
	Fixed();									// Constructor por defecto
	Fixed(const Fixed& other);					// Constructor de copia
	Fixed& operator=(const Fixed& other);		// Operador de asignación
	~Fixed();									// Destructor

	// 🔹 Constructores adicionales
	Fixed(const int intValue);					// Convierte un entero a punto fijo
	Fixed(const float floatValue);				// Convierte un flotante a punto fijo

	// 🔹 Getters / Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// 🔹 Conversiones
	float	toFloat(void) const;
	int		toInt(void) const;

	// 🔹 Operadores de comparación
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// 🔹 Operadores aritméticos
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	// 🔹 Operadores de incremento/decremento
	Fixed&	operator++();		// Pre-incremento (++a)
	Fixed	operator++(int);	// Post-incremento (a++)
	Fixed&	operator--();		// Pre-decremento (--a)
	Fixed	operator--(int);	// Post-decremento (a--)

	// 🔹 Funciones estáticas min / max
	static Fixed&			min(Fixed& a, Fixed& b);
	static const Fixed&		min(const Fixed& a, const Fixed& b);
	static Fixed&			max(Fixed& a, Fixed& b);
	static const Fixed&		max(const Fixed& a, const Fixed& b);
};

// 🔹 Operador de inserción <<
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
