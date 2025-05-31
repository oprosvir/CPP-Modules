/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:22:55 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/31 16:49:15 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <limits>

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
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

static bool isIntLiteral(const std::string& str) {
    char* end;
    std::strtol(str.c_str(), &end, 10);
    return *end == '\0';
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

void ScalarConverter::convert(const std::string& literal) {
    const int minInt = std::numeric_limits<int>::min();
    const int maxInt = std::numeric_limits<int>::max();

    if (isCharLiteral(literal))
        return printFromChar(literal[0]);
    else if (isIntLiteral(literal)) {
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (val < minInt || val > maxInt) {
            std::cerr << "Error: int overflow" << std::endl;
            return ;
        }
        return printFromInt(static_cast<int>(val));
    } else
        std::cerr << "Error: invalid literal format" << std::endl;
}
