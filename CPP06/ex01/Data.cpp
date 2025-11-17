/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:34:51 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:34:51 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("default"), _value(0) {}

Data::Data(const std::string &name, int value) : _name(name), _value(value) {}

Data::Data(const Data &src) { *this = src; }

Data &Data::operator=(const Data &src) {
    if (this != &src) {
        _name = src._name;
        _value = src._value;
    }
    return *this;
}

Data::~Data() {}

const std::string &Data::getName() const { return _name; }
int Data::getValue() const { return _value; }
