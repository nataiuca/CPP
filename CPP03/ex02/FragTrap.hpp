/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:16:34 by natferna          #+#    #+#             */
/*   Updated: 2025/10/29 00:16:35 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Orthodox Canonical Form
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap & operator=(const FragTrap& other);
	virtual ~FragTrap(void);

	// Nueva acción
	void highFivesGuys(void);
};

#endif
