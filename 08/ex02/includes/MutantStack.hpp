/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 17:37:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

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

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef typename \
			std::stack<T>::container_type::iterator iterator;
		typedef typename \
			std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename \
			std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename \
			std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin() { return(this->c.begin()); }
		iterator end() { return(this->c.end()); }
		const_iterator begin() const { return(this->c.begin()); }
		const_iterator end() const { return(this->c.end()); }
		const_reverse_iterator rbegin(void) const { return (this->c.rbegin()); };
		const_reverse_iterator rend(void) const { return (this->c.rend()); };
		reverse_iterator rbegin(void) { return (this->c.rbegin()); };
		reverse_iterator rend(void) {  return (this->c.rend()); };

		MutantStack()
		{
			std::cout << "MutantStack default constructor called." << std::endl;
		};
		MutantStack(const MutantStack &ref)
		{
			*this = ref;
		};
		~MutantStack()
		{
			std::cout << "MutantStack destructor called." << std::endl;
		}
		MutantStack &operator=(const MutantStack &ref)
		{
			this->stack = ref.stack;
			return (*this); 
		};
};
