/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:22:55 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/31 22:07:28 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

static bool isCharLiteral(const std::string& str) {
    return str.length() == 1 && !std::isdigit(str[0]);
}

static void printFromChar(char c) {
    std::cout << "char: ";
    if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static bool isIntLiteral(const std::string& str) {
    char* end;
    errno = 0;
    long val = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE &&
           val >= INT_MIN && val <= INT_MAX;
}

static void printFromInt(int i) {
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(i))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(i) << "'\n";
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static bool isFloatLiteral(const std::string& str) {
    char* end;
    std::strtof(str.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static void printFromFloat(float f) {
    std::cout << "char: ";
    if (std::isnan(f) || f < 0 || f > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(f) << "'\n";

    std::cout << "int: ";
    if (f < static_cast<float>(INT_MIN) ||
        f > static_cast<float>(INT_MAX) || std::isnan(f))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(f) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static bool isDoubleLiteral(const std::string& str) {
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

static void printFromDouble(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";

    std::cout << "int: ";
    if (d < static_cast<double>(INT_MIN) ||
        d > static_cast<double>(INT_MAX) || std::isnan(d))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << std::endl;
    
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (isCharLiteral(literal))
        return printFromChar(literal[0]);
    else if (isIntLiteral(literal)) {
        int i = std::strtol(literal.c_str(), NULL, 10);
        return printFromInt(i);
    } else if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        return printFromFloat(f);
    } else if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        return printFromDouble(d);
    } else
        std::cerr << "Error: invalid literal format" << std::endl;
}
