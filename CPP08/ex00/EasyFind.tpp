/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:38:10 by natferna          #+#    #+#             */
/*   Updated: 2025/11/12 21:38:10 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
