/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:44:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/04 18:00:56 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
        throw std::runtime_error("Error");

    int b = stack.top(); stack.pop();
    int a = stack.top(); stack.pop();

    switch (op) {
        case '+': stack.push(a + b); break;
        case '-': stack.push(a - b); break;
        case '*': stack.push(a * b); break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            stack.push(a / b);
            break;
        default:
            throw std::runtime_error("Error");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;

    for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
        char c = *it;
        if (c == ' ')
            continue;

        if (isdigit(c)) {
            stack.push(c - '0');
        }
        else if (isOperator(c)) {
            applyOperator(stack, c);
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}