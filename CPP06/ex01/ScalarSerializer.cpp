/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSerializer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:36:05 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:36:05 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarSerializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
