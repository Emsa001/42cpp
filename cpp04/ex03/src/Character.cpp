/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:52 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:29:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character() : _name("Character")
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << PURPLE400 "💂 Character" RESET " "
        << "Default Constructor called" << std::endl;

    for (int i = 0; i < INVENTORY_SIZE; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << PURPLE400 "💂 Character" RESET " "
        << "Parametrical Constructor called: " BOLD PURPLE400 << name
        << RESET << std::endl;

    for (int i = 0; i < INVENTORY_SIZE; i++)
        this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << PURPLE400 "💂 Character" RESET " "
        << "Copy Constructor called" << std::endl;

    Character::operator=(src);
}

Character::~Character()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET 
        << PURPLE400 "🪦 Character" RESET " "
        << "Destructor called" << std::endl;
    
    for(int i = 0; i < INVENTORY_SIZE; i++){
        if(this->_inventory[i] != NULL){
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(Character const &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET 
        << PURPLE400 "💂 Character" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_name = src.getName();
    for (int i = 0; i < INVENTORY_SIZE; i++){
        if(src._inventory[i] != NULL)     
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }

    return *this;
}

// Member functions

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    if (m == NULL)
    {
        std::cout
            << BG_RED900 "[    EQUIP    ]" RESET " Is this some enchantment?"
            << "Oh yes! " RED400 BOLD "NULL" RESET " weapon... You must be that smart guy 🤓"
            << std::endl;
        return;
    }

    int i = 0;
    while (i < INVENTORY_SIZE && _inventory[i] != NULL)
        i++;
    this->_inventory[i] = m;
  
    std::cout
        << BG_INDIGO700 "[    EQUIP    ]" RESET "💂 "
        << BOLD BLUE200 << this->getName()
        << RESET " equiped " BOLD RED300 << m->getType() << RESET << std::endl;
}

void Character::unequip(int idx)
{
    if (idx > INVENTORY_SIZE || _inventory[idx] == NULL)
    {
        std::cout
            << BG_INDIGO800 "[   UNEQUIP   ]" RESET "💂 "
            << BOLD BLUE200 << this->getName()
            << RESET " tried to unequip something he doesn't equip "
            << BOLD RED400 << this->getName() << RESET RED400 " must be " BOLD "special... 🫠" RESET << std::endl;

        return;
    }

    std::cout
        << BG_INDIGO800 "[   UNEQUIP   ]" RESET "💂 "
        << BOLD BLUE200 << this->getName()
        << RESET " unequiped " BOLD RED300 << this->_inventory[idx]->getType() << RESET << std::endl;


    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx > INVENTORY_SIZE || _inventory[idx] == NULL)
        return;

    _inventory[idx]->use(target);
}