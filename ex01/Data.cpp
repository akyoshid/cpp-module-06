/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:47:43 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 11:49:31 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

std::ostream& operator<<(std::ostream& lhs, const Data& rhs) {
    lhs << rhs.name << "(" << rhs.age << ")";
    return lhs;
}
