/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSerializer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:35:40 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:35:40 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {

private:
    Serializer();
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &src);
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);
    static Data*     deserialize(uintptr_t raw);
};

#endif
