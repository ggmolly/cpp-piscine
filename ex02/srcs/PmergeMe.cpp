/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:08:59 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 15:45:14 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

// Merge sort functions
void mergeSortVector(std::vector<int> &ref, int left, int mid, int right)
{
    int subOne = mid - left + 1;
    int subTwo = right - mid;

    // Create slices
    std::vector<int> leftSlice;
    std::vector<int> rightSlice;

    // Fill slices
    for (int i = 0; i < subOne; i++)
        leftSlice.push_back(ref[left + i]);
    for (int i = 0; i < subTwo; i++)
        rightSlice.push_back(ref[mid + 1 + i]);

    // Keep track of the indexes
    int indexLeft = 0;
    int indexRight = 0;
    int indexMerged = left;
    
    // Merge the slices
    while (indexLeft < subOne && indexRight < subTwo)
    {
        if (leftSlice.front() <= rightSlice.front())
        {
            ref[indexMerged] = leftSlice.front();
            leftSlice.erase(leftSlice.begin());
            indexLeft++;
        }
        else
        {
            ref[indexMerged] = rightSlice.front();
            rightSlice.erase(rightSlice.begin());
            indexRight++;
        }
        indexMerged++;
    }

    // Copy the remaining elements of leftSlice if there are any
    while (indexLeft < subOne)
    {
        ref[indexMerged] = leftSlice.front();
        leftSlice.erase(leftSlice.begin());
        indexLeft++;
        indexMerged++;
    }
}

void sliceVector(std::vector<int> &ref, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    sliceVector(ref, begin, mid);
    sliceVector(ref, mid + 1, end);
    mergeSortVector(ref, begin, mid, end);
}

std::list<int>::iterator at(std::list<int> &ref, size_t index)
{
    std::list<int>::iterator it = ref.begin();
    for (size_t i = 0; i < index; i++)
        it++;
    return it;
}

void mergeSortList(std::list<int> &ref, int left, int mid, int right)
{
    int subOne = mid - left + 1;
    int subTwo = right - mid;

    // Create slices
    std::list<int> leftSlice;
    std::list<int> rightSlice;

    // Fill slices
    for (int i = 0; i < subOne; i++)
        leftSlice.push_back(*at(ref, left + i));
    for (int i = 0; i < subTwo; i++)
        rightSlice.push_back(*at(ref, mid + 1 + i));

    // Keep track of the indexes
    int indexLeft = 0;
    int indexRight = 0;
    int indexMerged = left;
    
    // Merge the slices
    while (indexLeft < subOne && indexRight < subTwo)
    {
        if (leftSlice.front() <= rightSlice.front())
        {
            *at(ref, indexMerged) = leftSlice.front();
            leftSlice.erase(leftSlice.begin());
            indexLeft++;
        }
        else
        {
            *at(ref, indexMerged) = rightSlice.front();
            rightSlice.erase(rightSlice.begin());
            indexRight++;
        }
        indexMerged++;
    }

    // Copy the remaining elements of leftSlice if there are any
    while (indexLeft < subOne)
    {
        *at(ref, indexMerged) = leftSlice.front();
        leftSlice.erase(leftSlice.begin());
        indexLeft++;
        indexMerged++;
    }
}

void sliceList(std::list<int> &ref, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    sliceList(ref, begin, mid);
    sliceList(ref, mid + 1, end);
    mergeSortList(ref, begin, mid, end);
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        char *err;
        double d = strtod(argv[i], &err);
        if (*err != '\0')
            throw std::invalid_argument("Invalid value " + std::string(argv[i]));
        if (d > INT_MAX || d < 0)
            throw std::out_of_range("Value " + std::string(argv[i]) + " out of range (int type)");
        _vector.push_back(d);
        _list.push_back(d);
    }
}

PmergeMe &PmergeMe::operator=(PmergeMe &rhs)
{
    if (this == &rhs)
        return *this;
    // deep copy of the array
    const std::vector<int>& _ref = rhs.getArray();
    for (size_t i = 0; i < _ref.size(); i++)
        _vector.push_back(_ref[i]);
    return *this;
}


PmergeMe::PmergeMe(PmergeMe &rhs)
{
    // std::cerr << "PmergeMe copy constructor called" << std::endl;
    *this = rhs;
}

PmergeMe::~PmergeMe()
{
    // std::cerr << "PmergeMe destructor called" << std::endl;
}

void PmergeMe::sort() {
    // -- std::vector --
    clock_t vectorStart, vectorEnd;
    vectorStart = clock();
    sliceVector(_vector, 0, _vector.size() - 1);
    vectorEnd = clock();

    // -- std::list --
    clock_t listStart, listEnd;
    listStart = clock();
    sliceList(_list, 0, _list.size() - 1);
    listEnd = clock();

    // update chronos
    _vectorChrono = (vectorEnd - vectorStart) / double(CLOCKS_PER_SEC);
    _listChrono = (listEnd - listStart) / double(CLOCKS_PER_SEC);

    // check that list is sorted, if not, throw an exception
    std::list<int>::iterator it = _list.begin();
    int prev = *it;
    it++;
    for (; it != _list.end(); it++) {
        if (*it < prev)
            throw std::runtime_error("List is not sorted");
        prev = *it;
    }
}

void PmergeMe::chrono() {
    // decide which unit to use
    std::string unit = "s";
    if (_vectorChrono < 0.001)
        unit = "us";
    else if (_vectorChrono < 1)
        unit = "ms";
    if (unit == "ms")
    {
        _vectorChrono *= 1000;
        _listChrono *= 1000;
    }
    else if (unit == "us")
    {
        _vectorChrono *= 1000000;
        _listChrono *= 1000000;
    }
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorChrono << " " << unit << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << _listChrono << " " << unit << std::endl;
}

const std::vector<int>& PmergeMe::getArray() const {
    return _vector;
}

std::ostream &operator<<(std::ostream &o, PmergeMe const &rhs)
{
    const std::vector<int> &ref = rhs.getArray();
    for (size_t i = 0; i < ref.size(); i++) {
        o << ref[i];
        if (i < ref.size() - 1)
            o << ", ";
    }
    return o;
}
