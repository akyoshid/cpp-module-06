/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:39:12 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 16:50:17 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int rand = std::rand();
    if (rand % 3 == 0) {
        return new A;
    } else if (rand % 3 == 1) {
        return new B;
    } else {
        return new C;
    }
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Null pointer" << std::endl;
    } else if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cerr << "Base" << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception& e) {
    }
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception& e) {
    }
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception& e) {
    }
    std::cerr << "Base" << std::endl;
}
