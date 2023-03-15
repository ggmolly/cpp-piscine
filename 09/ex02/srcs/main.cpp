/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:01:06 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 15:44:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " positive numbers..." << std::endl;
        return (1);
    }

    try {
        PmergeMe pmerge(argc - 1, argv + 1); // Skip program name
        std::cout << "Before: " << pmerge << std::endl;
        pmerge.sort();
        std::cout << "After: " << pmerge << std::endl;
        pmerge.chrono();
    } catch (std::exception &e) {
        std::cerr << "Failed to sort : " <<  e.what() << std::endl;
        return (1);
    }
}
