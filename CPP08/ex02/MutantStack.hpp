/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:49:54 by natferna          #+#    #+#             */
/*   Updated: 2025/11/15 00:49:54 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// MutantStack: a std::stack with iterators exposed.
// Template parameters:
//  T         : value type
//  Container : underlying container type (defaults to std::deque<T> as in std::stack)
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	// orthodox canonical-like for template class:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	// iterator typedefs from underlying container
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// begin / end
	iterator begin() { return this->c.begin(); }
	iterator end()   { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end()   const { return this->c.end(); }

	// reverse iterators
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend()   { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend()   const { return this->c.rend(); }
};

#endif
