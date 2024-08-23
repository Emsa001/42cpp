/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:11 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:06:18 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    std::cout << "🤖 HumanB " << name << " constructor called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "🔥 HumanB " << this->_name << " destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << "🔫 HumanB " << this->_name << " weapon set to " << weapon.getType() << std::endl;
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << " 💥" << std::endl;
}
