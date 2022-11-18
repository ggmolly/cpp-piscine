/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:39:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include "time.h"

# define DODGERBLUE2 "\033[38;5;27m"
# define HOTPINK1 "\033[38;5;205m"
# define HOTPINK2 "\033[38;5;206m"
# define LIGHTGOLDENROD1 "\033[38;5;227m"
# define LIGHTGOLDENROD2 "\033[38;5;186m"
# define LIGHTSLATEGREY "\033[38;5;103m"
# define MEDIUMSPRINGGREEN "\033[38;5;49m"
# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define RESET "\033[0m"

class Span
{
	private:
		unsigned int		_limit;
		std::vector<int>	_numbers;
	public:
		/* ========== Constructors ========== */
		Span(void);
		Span(unsigned int max);
		Span(const Span &ref);
		
		/* ========== Destructor ========== */
		~Span(void);
		
		/* ========== Operators ========== */
		Span &operator=(const Span &ref);

		/* ========== Methods ========== */
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void print() const;
};

std::ostream& operator<<(std::ostream& os, const Span &ref);
