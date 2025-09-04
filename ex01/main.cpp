/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:45:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 14:31:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d = {"akyoshid", 25};
    std::cout << "=== Data ===" << std::endl;
    std::cout << "Data: " << d << std::endl;
    std::cout << "Address: " << &d << std::endl;
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "=== uintptr_t ===" << std::endl;
    std::cout << "Data: " << *(Serializer::deserialize(raw)) << std::endl;
    std::cout << "Address: 0x" << std::hex << raw << std::dec << std::endl;
    return 0;
}
