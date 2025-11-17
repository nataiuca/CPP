/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:25:46 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 18:25:46 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const &x)
{
    std::cout << x << std::endl;
}

class Awesome {
public:
    Awesome(void) : _n(42) {}
    int get_n() const { return _n; }

private:
    int _n;
};

std::ostream & operator<<(std::ostream &o, Awesome const &a)
{
    o << a.get_n();
    return o;
}

int main()
{
    int arrInt[5] = {1, 2, 3, 4, 5};
    std::string arrStr[3] = {"hola", "42", "cpp"};
    Awesome arrAws[2];

    std::cout << "INT:\n";
    iter(arrInt, 5, printElement);

    std::cout << "\nSTRING:\n";
    iter(arrStr, 3, printElement);

    std::cout << "\nAWESOME:\n";
    iter(arrAws, 2, printElement);

    return 0;
}
