/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:53:38 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:53:38 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

// -----------------------------------------------------------------------------
// Base class (abstract interface)
// -----------------------------------------------------------------------------
class Base {
public:
    virtual ~Base(); // virtual destructor ensures polymorphic behavior
};

// -----------------------------------------------------------------------------
// Class A – Canonical Form
// -----------------------------------------------------------------------------
class A : public Base {
public:
    A();                      // Default constructor
    A(const A &other);        // Copy constructor
    A &operator=(const A &other); // Copy assignment operator
    ~A();                     // Destructor
};

// -----------------------------------------------------------------------------
// Class B – Canonical Form
// -----------------------------------------------------------------------------
class B : public Base {
public:
    B();
    B(const B &other);
    B &operator=(const B &other);
    ~B();
};

// -----------------------------------------------------------------------------
// Class C – Canonical Form
// -----------------------------------------------------------------------------
class C : public Base {
public:
    C();
    C(const C &other);
    C &operator=(const C &other);
    ~C();
};

// -----------------------------------------------------------------------------
// Free functions 
// -----------------------------------------------------------------------------
Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif