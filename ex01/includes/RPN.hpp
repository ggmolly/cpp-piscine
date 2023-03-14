/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:04:46 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 13:46:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <cstdlib>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <sstream>

class RPN
{
    public:
        RPN();
        RPN(const std::string &expression);
        RPN &operator=(RPN &ref);
        RPN(RPN &src);
        ~RPN();
        unsigned long getResult();
    private:
        std::string _expression;
        unsigned long _result;
        std::stack<unsigned long> _stack;
};
