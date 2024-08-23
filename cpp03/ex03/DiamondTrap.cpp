/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:55:51 by escura            #+#    #+#             */
/*   Updated: 2024/08/16 16:40:57 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor and Destructor

DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap"), ScavTrap("DiamondTrap"), FragTrap("DiamondTrap"){
    this->_name = "DiamondTrap";
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout 
        << "✅  " << CYAN << "DiamondTrap " << _name 
        << " is ready to fight!" 
        << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name){
    this->_name = name + "_clap";
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout 
        << "✅  " << CYAN << "DiamondTrap " << _name 
        << " is ready to fight!" 
        << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src){
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
    if (this == &src)
        return (*this);
    this->_name = src._name;
    this->_hitpoints = src._hitpoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout 
        << "💀  " << CYAN << "DiamondTrap " << _name 
        << " is destroyed!" 
        << RESET << std::endl;
}

// Member functions

void DiamondTrap::whoAmI(){
    std::cout 
        << "🔹  " << CYAN << "DiamondTrap " << _name 
        << " is a " << _name << " and a " << ClapTrap::_name 
        << " at the same time!" 
        << RESET << std::endl;
}
