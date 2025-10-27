#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(3.0f, 3.0f);
	Point outside(10.0f, 2.0f);
	Point edge(5.0f, 0.0f);

	std::cout << std::boolalpha;
	std::cout << "Inside test: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside test: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Edge test: " << bsp(a, b, c, edge) << std::endl;

	return 0;
}
