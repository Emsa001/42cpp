/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:41:38 by escura            #+#    #+#             */
/*   Updated: 2024/08/13 14:09:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Initialize static member
ClapTrap* ClapTrap::claptraps[MAX_CLAPTRAPS] = { NULL };

// Constructor and Destructor
ClapTrap::ClapTrap() : _name("Claptrap"), _hitpoints(10), _energyPoints(10), _attackDamage(0) {
    putClaptrap(this);
    std::cout 
        << "✅  " << CYAN << "Claptrap " << _name 
        << " is ready to fight!"
        << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0) {
    putClaptrap(this);
    std::cout 
        << "✅  " << CYAN << "Claptrap " << _name 
        << " is ready to fight!" 
        << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    *this = src;
    putClaptrap(this);
    std::cout 
        << "✅  " << CYAN << "Claptrap " << _name 
        << " is cloned!" 
        << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    if (this != &src) {
        _name = src._name;
        _hitpoints = src._hitpoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    removeClaptrap(this);
    std::cout 
        << "☠️   " << RED << "Claptrap " << _name 
        << " is destroyed!" 
        << RESET << std::endl;
}

// Private helper functions

void ClapTrap::putClaptrap(ClapTrap *claptrap) {
    for (int i = 0; i < MAX_CLAPTRAPS; ++i) {
        if (claptraps[i] == NULL) {
            claptraps[i] = claptrap;
            return;
        }
    }
    std::cerr << "❌ Error: Maximum number of ClapTraps reached." << std::endl;
}

void ClapTrap::removeClaptrap(ClapTrap *claptrap) {
    for (int i = 0; i < MAX_CLAPTRAPS; ++i) {
        if (claptraps[i] == claptrap) {
            claptraps[i] = NULL;
            return;
        }
    }
}

ClapTrap* ClapTrap::getClaptrap(const std::string &name) const {
    for (int i = 0; i < MAX_CLAPTRAPS; ++i) {
        if (claptraps[i] != NULL && claptraps[i]->_name == name) {
            return claptraps[i];
        }
    }
    return NULL;
}

// Public functions

void ClapTrap::attack(const std::string &target) {
    if (!verify()) return;

    ClapTrap *targetClaptrap = getClaptrap(target);
    if (targetClaptrap == NULL) {
        std::cout 
            << "🧐  " << YELLOW << "Claptrap " << target 
            << " not found!" 
            << RESET << std::endl;
        return;
    }

    std::cout 
        << "⚔️   " << BLUE << "Claptrap " << _name 
        << " attacks " << target 
        << ", causing " << _attackDamage 
        << " points of damage!" 
        << RESET << std::endl;
        
    _energyPoints--;
    targetClaptrap->takeDamage(_attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitpoints = (_hitpoints > amount) ? _hitpoints - amount : 0;
    std::cout 
        << "🩸  " << ORANGE << "Claptrap " << _name 
        << " takes " << amount << " points of damage!" 
        << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!verify()) return;

    _hitpoints += amount;
    _energyPoints--;
    std::cout 
        << "❤️   " << GREEN << "Claptrap " << _name 
        << " is repaired for " << amount
        << " points!" << RESET << std::endl;
}

void ClapTrap::info() const {
    std::cout 
        << "❔  " << AQUA << "Claptrap " << _name << " has " 
        << _hitpoints << " hitpoints, " 
        << _energyPoints << " energy points, and " 
        << _attackDamage << " attack damage!" 
        << RESET << std::endl;
}

bool ClapTrap::verify() const {
    if (_hitpoints == 0) {
        std::cout 
            << "💀  " << RED << "Claptrap " << _name 
            << " is dead!" 
            << RESET << std::endl;
        return false;
    }
    if (_energyPoints == 0) {
        std::cout 
            << "😮‍💨  " << YELLOW << "Claptrap " << _name 
            << " is out of energy!" 
            << RESET << std::endl;
        return false;
    }
    return true;
}
