/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:03:47 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:03:48 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    AMateria(AMateria const & other);
    virtual ~AMateria();

    AMateria & operator=(AMateria const & other);

    std::string const & getType() const; // Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter & target);
};

#endif
