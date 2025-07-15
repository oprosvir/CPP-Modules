/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:44:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/15 16:08:58 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

// canonical form
RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

static void applyOperator(std::stack<int>& stack, char op) {
    if (stack.size() < 2)
        throw std::runtime_error("Error: not enough operands for operator '" + std::string(1, op) + "'");

    int b = stack.top(); stack.pop();
    int a = stack.top(); stack.pop();

    switch (op) {
        case '+': stack.push(a + b); break;
        case '-': stack.push(a - b); break;
        case '*': stack.push(a * b); break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            stack.push(a / b);
            break;
        default:
            throw std::runtime_error("Error");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        // std::cout << "[" << token << "] ";
        if (token.length() == 1 && isdigit(token[0])) {
            stack.push(token[0] - '0');
        }
        else if (token.length() == 2 && token[0] == '-' && isdigit(token[1]) && token[1] != '0') {
            stack.push(-(token[1] - '0'));
        }
        else if (token.length() == 1 && isOperator(token[0]))
            applyOperator(stack, token[0]);
        else
            throw std::runtime_error("Error: invalid token '" + token + "'");
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");

    return stack.top();
}