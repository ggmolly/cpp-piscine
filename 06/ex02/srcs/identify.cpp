/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:36:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 17:07:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identified as : A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Identified as : B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Identified as : C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &temp = dynamic_cast<A&>(p);
		(void) temp;
		std::cout << "Identified as : A" << std::endl;
	}
	catch (const std::exception &e) { (void) e; }
	try
	{
		B &temp = dynamic_cast<B&>(p);
		(void) temp;
		std::cout << "Identified as : B" << std::endl;
	}
	catch (const std::exception &e) { (void) e; }
	try
	{
		C &temp = dynamic_cast<C&>(p);
		(void) temp;
		std::cout << "Identified as : C" << std::endl;
	}
	catch (const std::exception &e) { (void) e; }
}
