/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:13:23 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 01:19:35 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <cstring>
# include <climits>
# include <stdlib.h>
# define LIGHTSLATEGREY "\033[38;5;103m"
# define RESET "\033[0m"

template <typename T>
class Array
{
	public:
		Array(void): _size(0), _array(NULL)
		{
			std::cout << LIGHTSLATEGREY << "Default array constructor called" << RESET << std::endl;
		}

		Array(unsigned int size): _size(size)
		{
			if (size > INT_MAX || size == 0)
				throw InvalidSizeException();
			std::cout << LIGHTSLATEGREY << "Array constructor called (size=" << size << ")" << RESET << std::endl;
			_array = new T[size];
			bzero(_array, sizeof(T) * _size);
		}

		Array(Array const &ref)
		{
			std::cout << LIGHTSLATEGREY << "Array copy constructor called" << RESET << std::endl;
			if (this != &ref)
				*this = ref;
		}

		~Array(void)
		{
			std::cout << LIGHTSLATEGREY << "Array destructor called" << RESET << std::endl;
			if (_array)
				delete [] _array;
		}

		unsigned int size(void) const
		{
			return _size;
		}

		Array &operator=(Array const &ref)
		{
			std::cout << LIGHTSLATEGREY << "Array assignation operator called" << RESET << std::endl;
			if (this != &ref)
			{
				if (_array)
					delete [] _array;
				_size = ref._size;
				_array = new T[_size];
				bzero(_array, sizeof(T) * _size);
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = ref._array[i];
			}
			return *this;
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw IndexOutOfBoundsException();
			return _array[i];
		}

		class IndexOutOfBoundsException : public std::exception {
			public:
				const char *what() const throw() {
					return "Index out of bounds";
				}
		};
		class InvalidSizeException : public std::exception {
			public:
				const char *what() const throw() {
					return "Invalid size (must be > 0 and < 2147483647)";
				}
		};
		
	private:
		T *_array;
		unsigned int _size;
};