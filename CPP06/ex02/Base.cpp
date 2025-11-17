/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:53:45 by natferna          #+#    #+#             */
/*   Updated: 2025/11/11 23:53:45 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// -----------------------------------------------------------------------------
// Base
// -----------------------------------------------------------------------------
Base::~Base() {}

// -----------------------------------------------------------------------------
// A – Canonical Form
// -----------------------------------------------------------------------------
A::A() {}
A::A(const A &other) { (void)other; }
A &A::operator=(const A &other) {
    (void)other;
    return *this;
}
A::~A() {}

// -----------------------------------------------------------------------------
// B – Canonical Form
// -----------------------------------------------------------------------------
B::B() {}
B::B(const B &other) { (void)other; }
B &B::operator=(const B &other) {
    (void)other;
    return *this;
}
B::~B() {}

// -----------------------------------------------------------------------------
// C – Canonical Form
// -----------------------------------------------------------------------------
C::C() {}
C::C(const C &other) { (void)other; }
C &C::operator=(const C &other) {
    (void)other;
    return *this;
}
C::~C() {}

// -----------------------------------------------------------------------------
// Functions required by the subject
// -----------------------------------------------------------------------------
Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int r = std::rand() % 3;

    if (r == 0) return new A();
    else if (r == 1) return new B();
    else return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
    else std::cout << "Unknown\n";
}

void identify(Base& p) {
    try { A &a = dynamic_cast<A&>(p); (void)a; std::cout << "A\n"; return; } catch (...) {}
    try { B &b = dynamic_cast<B&>(p); (void)b; std::cout << "B\n"; return; } catch (...) {}
    try { C &c = dynamic_cast<C&>(p); (void)c; std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown\n";
}
