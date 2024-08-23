/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:38 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:05:39 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
	this->_name = name;
	std::cout << "🧟 Zombie " << name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🪦 " << this->_name << ": died :(" << std::endl;
}

void Zombie::announce()
{
	std::cout << "👀 " << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
