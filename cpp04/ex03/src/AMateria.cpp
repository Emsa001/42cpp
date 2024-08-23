/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:46:52 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:01:26 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(): _type("Some unknown materia"){
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 "🔋 AMateria" RESET " "
        << "Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type){
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 "🔋 AMateria" RESET " "
        << "Parametrical Constructor called: " BOLD LIME400 << type
        << RESET << std::endl;
}

AMateria::AMateria(AMateria const &src){
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 "🔋 AMateria" RESET " "
        << "Copy Constructor called" << std::endl;

    AMateria::operator=(src);
}

AMateria::~AMateria(){
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET 
        << RED400 "🪫 AMateria" RESET " "
        << "Destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET 
        << LIME400 "🪫 AMateria" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_type = src._type;

    return *this;
}

void AMateria::use(ICharacter &target){
    (void)target;
}

std::string const &AMateria::getType() const{
    return this->_type;
}

