/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:05:32 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 19:05:32 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // std::out_of_range
#include <cstdlib>   // size_t

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // 🧱 Forma canónica
    Array() : _array(NULL), _size(0) {}

    Array(unsigned int n) : _array(new T[n]()), _size(n) {}

    Array(const Array &other) : _array(NULL), _size(0) {
        *this = other;
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return *this;
    }

    ~Array() {
        delete[] _array;
    }

    // 🔹 Acceso seguro con operador []
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    const T &operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    // 🔹 Tamaño actual del array
    unsigned int size() const {
        return _size;
    }
};

#endif