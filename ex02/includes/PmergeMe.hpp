/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:07:17 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 15:44:44 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <fstream>
#include <list>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe &operator=(PmergeMe &ref);
        PmergeMe(PmergeMe &src);
        ~PmergeMe();
        void sort();
        void chrono();
        const std::vector<int>& getArray() const;
    private:
        std::vector<int> _vector;
        std::list<int> _list;
        double _vectorChrono;
        double _listChrono;
};
std::ostream &operator<<(std::ostream &o, PmergeMe const &rhs);
