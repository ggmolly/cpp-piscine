/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:58:37 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 16:52:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &expression) {
    this->_expression = expression;
    const std::string validChars = "012345789+-*/ ";
    for (size_t i = 0; i < expression.length(); i++) {
        if (validChars.find(expression[i]) == std::string::npos)
            throw std::invalid_argument("Invalid character in expression");
    }

    // Compute expression
    std::stringstream expressionStream(expression);
    std::string token;
    while (expressionStream >> token)
    {
        // Get next token, push it to stack
        long tokenNumber;
        if (std::istringstream(token) >> tokenNumber)
        {
            if (tokenNumber >= 10)
                throw std::invalid_argument("Found number greater than 10");
            _stack.push(tokenNumber);
        }
        else
        {
            if (_stack.size() != 2)
                throw std::invalid_argument("Invalid expression");
            long secondOp = _stack.top();
            _stack.pop();
            long firstOp = _stack.top();
            _stack.pop();
            switch (token[0])
            {
                case '+':
                    _stack.push(firstOp + secondOp);
                    break;
                case '-':
                    _stack.push(firstOp - secondOp);
                    break;
                case '*':
                    _stack.push(firstOp * secondOp);
                    break;
                case '/':
                    if (secondOp == 0)
                        throw std::invalid_argument("Division by zero");
                    _stack.push(firstOp / secondOp);
                    break;
                default:
                    throw std::invalid_argument("Invalid operator");
            }
        }
    }
    if (_stack.size() != 1)
        throw std::invalid_argument("Invalid expression");
    this->_result = _stack.top();
}

RPN &RPN::operator=(RPN &rhs)
{
    if (this != &rhs)
    {
        this->_expression = rhs._expression;
        this->_result = rhs._result;
        this->_stack = rhs._stack;
    }
    return *this;
}

RPN::RPN(RPN &src)
{
    // std::cerr << "RPN copy constructor called" << std::endl;
    *this = src;
}

RPN::~RPN()
{
    // std::cerr << "RPN destructor called" << std::endl;
}

long RPN::getResult() {
    return this->_result;
}
