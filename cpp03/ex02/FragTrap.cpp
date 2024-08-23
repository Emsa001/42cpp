/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:44:15 by escura            #+#    #+#             */
/*   Updated: 2024/08/13 15:48:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout
        << GREEN << "✅  " << CYAN << "Fragtrap " << _name
        << " is ready to fight!"
        << RESET << std::endl;
    std::cout << "✅  " << YELLOW << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

    std::cout << "✅  " << BLUE << "FragTrap constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    std::cout << "✅  " << MAGENTA << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        _name = src._name;
        _hitpoints = src._hitpoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }

    std::cout << "✅  " << AQUA << "FragTrap assignation operator called" << RESET << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "💀  " << YELLOW << "FragTrap destructor called" << RESET << std::endl;
}

// Public

void FragTrap::highFivesGuys()
{
    std::cout << "🖐   " << GREEN << "FragTrap " << this->_name << " is asking for a high five!" << RESET << std::endl;
}