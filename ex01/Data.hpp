/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:40:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 11:48:41 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_DATA_HPP_
# define EX01_DATA_HPP_

# include <string>
# include <iostream>

typedef struct {
    std::string name;
    int age;
} Data;

std::ostream& operator<<(std::ostream& lhs, const Data& rhs);

#endif
