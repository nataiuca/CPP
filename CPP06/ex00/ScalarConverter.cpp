/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:16:19 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:16:19 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isPseudoLiteral(const std::string &s) {
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "+inff" ||
            s == "-inf" || s == "-inff" ||
            s == "inf"  || s == "inff");
}

void ScalarConverter::convert(const std::string &literal) {

    std::cout << std::fixed << std::setprecision(1);

    // ✅ Pseudoliterals
    if (isPseudoLiteral(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";

        if (literal[literal.length() - 1] == 'f')
            std::cout << "float: " << literal << "\n";
        else
            std::cout << "float: " << literal << "f\n";

        if (literal[literal.length() - 1] == 'f')
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
        else
            std::cout << "double: " << literal << "\n";
        return;
    }

    // ✅ Single char literal
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }

    // ✅ Detect if literal has 'f'
    bool isFloatLiteral = (literal[literal.length() - 1] == 'f');
    std::string toConvert = literal;

    if (isFloatLiteral)
        toConvert = literal.substr(0, literal.length() - 1);

    // ✅ Convert using strtod (C++98 OK)
    char *endPtr = NULL;
    double value = std::strtod(toConvert.c_str(), &endPtr);

    // Si endPtr no llega al final → input inválido
    if (*endPtr != '\0') {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    // ✅ CHAR
    if (value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(value) << "'\n";

    // ✅ INT
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    // ✅ FLOAT
    std::cout << "float: " << static_cast<float>(value) << "f\n";

    // ✅ DOUBLE
    std::cout << "double: " << value << "\n";
}

ScalarConverter::~ScalarConverter() {}