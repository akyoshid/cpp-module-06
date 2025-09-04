/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:29:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:57kyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include "ScalarConverter.hpp"

//
// helper functions to check the type
//
static bool isPseudoLiteral(const std::string& literal) {
    if (literal == "nanf" || literal == "inff"
        || literal == "+inff" || literal == "-inff"
        ||literal == "nan" || literal == "inf"
        || literal == "+inf" || literal == "-inf")
        return true;
    else
        return false;
}

static bool isChar(const std::string& literal) {
    if (literal.length() == 3
        && literal[0] == '\''
        && literal[2] == '\'')
        return true;
    else
        return false;
}

static bool isInt(const std::string& literal) {
    if (literal.empty())
        return false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i >= literal.length())
        return false;
    for (; i < literal.length(); i++) {
        if (std::isdigit(static_cast<unsigned char>(literal[i])) == false)
            return false;
    }
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal.empty())
        return false;
    if (literal[literal.length() - 1] != 'f')
        return false;
    std::string num = literal.substr(0, literal.length() - 1);
    if (num.empty())
        return false;
    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;
    if (num[i] == '+' || num[i] == '-')
        i++;
    for (; i < num.length(); i++) {
        if (num[i] == '.') {
            if (hasDot == true)
                return false;
            hasDot = true;
        } else if (std::isdigit(static_cast<unsigned char>(num[i]))) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    return hasDot && hasDigit;
}

static bool isDouble(const std::string& literal) {
    if (literal.empty())
        return false;
    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot == true)
                return false;
            hasDot = true;
        } else if (std::isdigit(static_cast<unsigned char>(literal[i]))) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    return hasDot && hasDigit;
}

//
// helper functions to check the precision
//
static void checkPrecision(
    const std::string& literal, int& decDigit, int& sigDigit) {
    bool afterDot = false;
    bool afterNonZero = false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            afterDot = true;
            continue;
        } else if (afterDot == true) {
            ++decDigit;
        }
        if (afterNonZero == true) {
            ++sigDigit;
        } else if (literal[i] != '0') {
            afterNonZero = true;
            ++sigDigit;
        }
    }
}

static int checkDoublePrecision(const std::string& literal) {
    int decDigit = 0;
    int sigDigit = 0;
    checkPrecision(literal, decDigit, sigDigit);
    if (decDigit > DOUBLE_MAX_DEC_DIGIT) {
        sigDigit -= decDigit - DOUBLE_MAX_DEC_DIGIT;
        decDigit = DOUBLE_MAX_DEC_DIGIT;
    }
    int ret = decDigit;
    if (sigDigit > DOUBLE_MAX_SIG_DIGIT) {
        ret -= sigDigit - DOUBLE_MAX_SIG_DIGIT;
    }
    if (ret <= 0)
        return 1;
    else
        return ret;
}

static int checkFloatPrecision(const std::string& literal) {
    int decDigit = 0;
    int sigDigit = 0;
    checkPrecision(literal, decDigit, sigDigit);
    if (decDigit > FLOAT_MAX_DEC_DIGIT) {
        sigDigit -= decDigit - FLOAT_MAX_DEC_DIGIT;
        decDigit = FLOAT_MAX_DEC_DIGIT;
    }
    int ret = decDigit;
    if (sigDigit > FLOAT_MAX_SIG_DIGIT) {
        ret -= sigDigit - FLOAT_MAX_SIG_DIGIT;
    }
    if (ret <= 0)
        return 1;
    else
        return ret;
}

//
// helper functions to print
//
static void printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < std::numeric_limits<char>::min()
        || value > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

static void printFloat(double value, int precision) {
    std::cout << "float: ";
    std::cout
        << std::fixed << std::setprecision(precision)
        << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value, int precision) {
    std::cout << "double: ";
    std::cout
        << std::fixed << std::setprecision(precision)
        << value << std::endl;
}

//
//
//
void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;
    int precision = 1;
    try {
        if (isPseudoLiteral(literal)) {
            value = std::strtod(literal.c_str(), NULL);
        } else if (isChar(literal)) {
            value = static_cast<double>(literal[1]);
        } else if (isFloat(literal)) {
            std::string num = literal.substr(0, literal.length() - 1);
            char* end;
            errno = 0;
            value = std::strtod(num.c_str(), &end);
            if (errno == ERANGE || *end != '\0') {
                throw std::exception();
            }
            precision = checkFloatPrecision(num);
        } else if (isDouble(literal)) {
            char* end;
            errno = 0;
            value = std::strtod(literal.c_str(), &end);
            if (errno == ERANGE || *end != '\0') {
                throw std::exception();
            }
            precision = checkDoublePrecision(literal);
        } else if (isInt(literal)) {
            char* end;
            errno = 0;
            long lval = std::strtol(literal.c_str(), &end, 10);
            if (errno == ERANGE || *end != '\0' || 
                lval < std::numeric_limits<int>::min() || 
                lval > std::numeric_limits<int>::max()) {
                throw std::exception();
            }
            value = static_cast<double>(lval);
        } else {
            throw std::exception();
        }
        printChar(value);
        printInt(value);
        printFloat(value, precision);
        printDouble(value, precision);
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
