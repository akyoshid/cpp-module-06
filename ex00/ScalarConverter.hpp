/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:29:18 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/03 15:07:17 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_ScalarConverter_HPP_
# define EX00_ScalarConverter_HPP_

# include <string>

# define DOUBLE_MAX_DEC_DIGIT 307
# define DOUBLE_MAX_SIG_DIGIT 15
# define FLOAT_MAX_DEC_DIGIT 37
# define FLOAT_MAX_SIG_DIGIT 6

class ScalarConverter {
 public:
    static void convert(const std::string& str);
 private:
    ScalarConverter(); // = delete
    ScalarConverter(const ScalarConverter& src); // = delete
    ScalarConverter& operator=(const ScalarConverter& literal); // = delete
    ~ScalarConverter(); // = delete
};

#endif
