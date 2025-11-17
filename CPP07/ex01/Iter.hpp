/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:16:18 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 18:16:18 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

// ✅ iter con función que no modifica
template <typename T>
void iter(T *array, size_t len, void (*func)(T const &))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

#endif
