/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 17:49:15 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ========== Constructors ========== */

Span::Span(void):
_limit(INT_MAX)
{
	std::cout << "Span default constructor." << std::endl;
	_numbers = std::vector<int>();
}

Span::Span(unsigned int max):
_limit(max)
{
	std::cout << "Span created with a limit of " << max << " numbers." << std::endl;
	_numbers = std::vector<int>();
}

Span::Span(const Span &ref)
{
	std::cout << "Span copy constructor called." << std::endl;
	if (this != &ref)
		*this = ref;
}

/* ========== Destructor ========== */

Span::~Span(void)
{
	std::cout << "Span destructor called." << std::endl;
}

/* ========== Operators ========== */

Span &Span::operator=(const Span &ref)
{
	std::cout << "Span assignment operator used." << std::endl;
	if (this != &ref)
	{
		this->_limit = ref._limit;
		this->_numbers = ref._numbers;
	}
	return (*this);
}

/* ========== Methods ========== */

void Span::addNumber(int n)
{
	if (_numbers.size() + 1 > _limit)
		throw std::overflow_error("Adding a number would exceed limit");
	_numbers.push_back(n);
}

int Span::shortestSpan()
{
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = INT_MAX;
	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1] - sorted[i] < min)
			min = sorted[i + 1] - sorted[i];
	}
	return min;
}

int Span::longestSpan()
{
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.at(sorted.size() - 1) - sorted.at(0));
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::vector<int> rangeCopy(start, end);
	if (_numbers.size() + rangeCopy.size() > _limit)
		throw std::overflow_error("Not enough space to add range");
	for (size_t i = 0; i < rangeCopy.size(); i++)
	{
		_numbers.push_back(rangeCopy.at(i));
	}
}

void Span::print() const
{
	unsigned int currentSize = this->_numbers.size();
	if (currentSize == 0)
	{
		std::cout << HOTPINK1 << "Span(" << this->_limit << ") = Empty";
		return ;
	}
	std::cout << (currentSize == this->_limit ? RED1 : SPRINGGREEN3) << "Span(" << this->_limit << ") = ";
	for (unsigned int i = 0; i < currentSize; i++)
	{
		std::cout << _numbers.at(i);
		if (i != currentSize - 1)
			std::cout << ", ";
	}
	std::cout << RESET;
}

std::ostream& operator<<(std::ostream& os, const Span &ref)
{
	ref.print();
	return (os);
}
