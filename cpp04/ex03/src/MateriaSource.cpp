/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:53:05 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:09:39 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET 
        << PINK400 "🧬 MateriaSource" RESET " "
        << "Default Constructor called" << std::endl;
    
    for (int i = 0; i < SOURCES_SIZE; i++)
        this->_sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET 
        << PINK400 "🧬 MateriaSource" RESET " "
        << "Copy Constructor called" << std::endl;

    MateriaSource::operator=(src);
}

MateriaSource::~MateriaSource()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET 
        << PINK400 "🦠 MaterialSource" RESET " "
        << "Destructor called" << std::endl;
        
    for (int i = 0; i < SOURCES_SIZE; i++){
        if(this->_sources[i] != NULL){
            delete this->_sources[i];
            this->_sources[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET 
        << PINK400 "🧬 MaterialSource" RESET " "
        << "Copy Assignment operator called" << std::endl;

    for (int i = 0; i < SOURCES_SIZE; i++)
        if(this->_sources[i] != NULL)
            this->_sources[i] = src._sources[i]->clone();

    return *this;
}

// Public members

void MateriaSource::learnMateria(AMateria *src)
{
    int i = 0;
    while (i < SOURCES_SIZE && this->_sources[i] != NULL)
        i++;

    if (i == SOURCES_SIZE)
    {
        std::cout
            << BG_RED900 BOLD GRAY100 "Oh nooo! That's too many materias!!! "
            << "You lost everything you learned! 😭" RESET
            << std::endl;
            
        for (int j = 0; j < SOURCES_SIZE; j++){
            delete this->_sources[j];
            this->_sources[j] = NULL;
        }

        delete src;
        return;
    }

    this->_sources[i] = src;

    std::cout
        << BG_BLUE500 "[    ACTION   ]" RESET
        << PINK400 "🧬 MaterialSource" RESET " "
        << "Learned " << BOLD PINK500 << src->getType() 
        << RESET << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < SOURCES_SIZE; i++)
    {
        if (this->_sources[i] && this->_sources[i]->getType() == type)
            return this->_sources[i]->clone();
    }

    return NULL;
}