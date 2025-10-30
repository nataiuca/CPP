/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:05:52 by natferna          #+#    #+#             */
/*   Updated: 2025/10/30 14:05:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* materias[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    ~MateriaSource();

    MateriaSource & operator=(MateriaSource const & other);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
