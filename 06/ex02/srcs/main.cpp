/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 17:12:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *secret = generate();
		std::cout << "Reference method" << std::endl << "\t";
		identify(*secret);
		std::cout << "Pointer method" << std::endl << "\t";
		identify(secret);
		delete secret;
		std::cout << "====================================" << std::endl;
	}
}