/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:45:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 11:51:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d = {"akyoshid", 25};
    std::cout << d << std::endl;
    uintptr_t addr = Serializer::serialize(&d);
    std::cout << *(Serializer::deserialize(addr)) << std::endl;
    return 0;
}
