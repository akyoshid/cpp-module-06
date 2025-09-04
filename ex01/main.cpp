/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:45:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 15:09:24 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d = {"akyoshid", 25};
    uintptr_t addr = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(addr);
    std::cout << "d:\t" << d << std::endl;
    std::cout << "&d:\t" << &d << std::endl;
    std::cout << "*ptr:\t" << *ptr << std::endl;
    std::cout << "addr:\t0x" << std::hex << addr << std::dec << std::endl;
    if (&d == ptr) {
        std::cout << "SUCCESS" << std::endl;
        return 0;
    }
    else {
        std::cerr << "FAILURE" << std::endl;
        return 1;
    }
}
