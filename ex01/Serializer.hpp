/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:37:40 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/04 11:44:11 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_SERIALIZER_HPP_
# define EX01_SERIALIZER_HPP_

# include <stdint.h>
# include "Data.hpp"

class Serializer {
 public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
 private:
    Serializer(); // = delete
    Serializer(const Serializer& src); // = delete
    Serializer& operator=(const Serializer& src); // = delete
    ~Serializer(); // = delete
};

#endif
