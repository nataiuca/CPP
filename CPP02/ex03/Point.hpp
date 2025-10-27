#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();                                // Constructor por defecto
    Point(const float x, const float y);    // Constructor con valores
    Point(const Point& other);              // Constructor de copia
    Point& operator=(const Point& other);   // Operador de asignación
    ~Point();                               // Destructor

    Fixed getX(void) const;                 // Getter
    Fixed getY(void) const;                 // Getter
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
