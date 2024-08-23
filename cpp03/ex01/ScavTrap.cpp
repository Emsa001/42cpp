/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:41:38 by escura            #+#    #+#             */
/*   Updated: 2024/08/15 14:05:00 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor and Destructor
ScavTrap::ScavTrap(): ClapTrap(){
    this->_name = "ScavTrap";
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    
    std::cout 
        << "✅  " << CYAN << "Scavtrap " << _name 
        << " is ready to fight!"
        << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_name = name;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    
    std::cout 
        << "✅  " << CYAN << "Scavtrap " << _name 
        << " is ready to fight!" 
        << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    *this = src;
    std::cout 
        << "✅  " << CYAN << "Scavtrap " << _name 
        << " is cloned!" 
        << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    if (this != &src) {
        _name = src._name;
        _hitpoints = src._hitpoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout 
        << "☠️   " << RED << "Scavtrap " << _name 
        << " is destroyed!" 
        << RESET << std::endl;
}


// Member functions

void ScavTrap::attack(std::string const &target){
    if (!verify()) return;

    ClapTrap *targetClaptrap = getClaptrap(target);
    if (targetClaptrap == NULL) {
        std::cout 
            << "🧐  " << YELLOW << target 
            << " not found!" 
            << RESET << std::endl;
        return;
    }

    std::cout 
        << "⚔️   " << BLUE << " [ SCAVTRAP ] " << _name 
        << " attacks " << target 
        << ", causing " << _attackDamage 
        << " points of damage!" 
        << RESET << std::endl;
        
    _energyPoints--;
    targetClaptrap->takeDamage(_attackDamage);
}


void ScavTrap::guardGate() {
    std::cout 
        << "🛡️   " << GREEN << "Scavtrap " << _name 
        << " has entered in Gate keeper mode!" 
        << RESET << std::endl;
}