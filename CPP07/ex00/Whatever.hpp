/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:57:07 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 17:57:07 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// Template función swap
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template función min
template <typename T>
T const &min(T const &a, T const &b) {
    return (b < a ? b : a);
}

// Template función max
template <typename T>
T const &max(T const &a, T const &b) {
    return (a < b ? b : a);
}

#endif
