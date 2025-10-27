#include "Point.hpp"

// Función auxiliar: calcula el área absoluta del triángulo (A,B,C)
static Fixed area(Point const a, Point const b, Point const c)
{
	return Fixed(std::abs(
		(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
		 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
		 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
	));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = area(a, b, c);
	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	// Si la suma de subáreas = área total y ninguna es 0 → dentro
	bool isInside = (areaABC == (areaPAB + areaPBC + areaPCA)) &&
					(areaPAB > Fixed(0)) && (areaPBC > Fixed(0)) && (areaPCA > Fixed(0));

	return isInside;
}
