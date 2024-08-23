/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:01:38 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:08:27 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Types.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << SKY400 "🧊 Ice" RESET " "
        << "Default Constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << SKY400 "🧊 Ice" RESET " "
        << "Copy Constructor called" << std::endl;

    Ice::operator=(src);
}

Ice::~Ice()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << SKY400 "🔥 Ice" RESET " "
        << "Destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &src)
{
    if (this == &src)
    {
        return *this;
    }

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET 
        << SKY400 "🧊 Ice" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_type = src._type;
    return *this;
}

AMateria *Ice::clone() const
{
    Ice* clone = new Ice(*this);
    return clone;
}

void Ice::use(ICharacter &target)
{
    std::cout
        << BG_BLUE500 "[    ACTION   ]" RESET
        << SKY400 "🧊 ICE" RESET " "
        << "* shoots an ice bolt at " BOLD BLUE400 << target.getName() << RESET " *" 
        << std::endl; 
}

// CURE

Cure::Cure() : AMateria("cure")
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << GREEN300 "❇️  Cure" RESET " "
        << "Default Constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << GREEN300 "❇️  Cure" RESET " "
        << "Copy Constructor called" << std::endl;

    Cure::operator=(src);
}

Cure::~Cure()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << GREEN300 "❇️  Cure" RESET " "
        << "Destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
    if (this == &src)
    {
        return *this;
    }

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET 
        << GREEN300 "❇️  Cure" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_type = src._type;
    return *this;
}

AMateria *Cure::clone() const
{
    Cure* clone = new Cure(*this);
    return clone;
}

void Cure::use(ICharacter &target)
{
    std::cout
        << BG_BLUE500 "[    ACTION   ]" RESET
        << GREEN300 "❇️  Cure" RESET " "
        << "* heals " BOLD BLUE400 << target.getName() << "'s" RESET " wounds *" 
        << std::endl; 
}
