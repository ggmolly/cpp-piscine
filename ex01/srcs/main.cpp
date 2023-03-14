/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:58:35 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 13:53:11 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return (1);
    }

    try {
        RPN rpn(argv[1]);
        std::cout << rpn.getResult() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Failed to evaluate expression: " << e.what() << std::endl;
        return (1);
    }
}
