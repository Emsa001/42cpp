/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:05 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:06:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "🤖 HumanA " << name << " constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "🔥 HumanA " << this->_name << " destructor called" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << " 💥" << std::endl;
}
