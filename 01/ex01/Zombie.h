/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:54:17 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/31 21:41:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# define RED "\033[0;31m"
# define RESET "\033[0m"

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

#endif