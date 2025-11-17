/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:34:43 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:34:43 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
    std::string _name;
    int         _value;

public:
    Data();
    Data(const std::string &name, int value);
    Data(const Data &src);
    Data &operator=(const Data &src);
    ~Data();

    const std::string &getName() const;
    int getValue() const;
};

#endif
