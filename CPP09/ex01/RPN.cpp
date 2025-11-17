/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:32:02 by natferna          #+#    #+#             */
/*   Updated: 2025/11/17 00:32:02 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ==================== CANONICAL FORM ====================

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }
RPN::~RPN() {}

// ==================== FUNCIONES ====================

bool RPN::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperation(int a, int b, const std::string &op) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

int RPN::evaluate(const std::string &expr) const {
    std::stack<int> s;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (s.size() < 2)
                throw std::runtime_error("Error");
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = applyOperation(a, b, token);
            s.push(result);
        } else {
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error");
            s.push(token[0] - '0');
        }
    }

    if (s.size() != 1)
        throw std::runtime_error("Error");

    return s.top();
}
