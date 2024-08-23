/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:49 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:26:49 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "unnamed";
	std::cout << "🧟 Zombie " << this->_name << " created" << std::endl;
}

Zombie::Zombie(const std::string &name)
{
	this->_name = name;
	std::cout << "🧟 Zombie " << name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🪦 " << this->_name << ": died :(" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << "👀 " << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
