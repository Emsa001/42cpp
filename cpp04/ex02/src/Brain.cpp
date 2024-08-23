/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:47:57 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 23:24:27 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Constructors and destructors

Brain::Brain()
{
    // for (int i = 0; i < MAX_IDEAS; i++)
    //     this->_ideas[i].clear();

    std::cout
        << PINK500 "🧠 Brain" RESET " "
        << "Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout
        << PINK500 "🧠 Brain" RESET " "
        << "Copy Constructor called" << std::endl;

    Brain::operator=(src);
}

Brain::~Brain()
{
    std::cout
        << PINK500 "🪦 Brain" RESET " "
        << "Destructor called" << std::endl;
}

// Operators

Brain &Brain::operator=(const Brain &src)
{
    if (this == &src)
        return *this;

    std::cout
        << PINK500 "🧠 Brain" RESET " "
        << "Copy Assignment operator called" << std::endl;

    for (int i = 0; i < MAX_IDEAS; i++){
        this->_ideas[i] = src._ideas[i];
    }

    return *this;
}

// public functions

void Brain::putIdea(std::string idea)
{
    int i = 0;
    while (i < MAX_IDEAS && this->_ideas[i] != "")
        i++;

    if(i == MAX_IDEAS){
        std::cout
            << BG_RED900 BOLD GRAY100 "🧠 Oh nooo! That's too many ideas!!! The brain exploded 🤯 and lost all ideas" RESET
            << std::endl;
        for (int j = 0; j < MAX_IDEAS; j++)
            this->_ideas[j].clear();

        return ;
    }

    this->_ideas[i] = idea;
    if(i == 0)
        std::cout
            << BG_INDIGO800 BOLD GRAY100 "🧠 Brain just brained it's first idea!" RESET
            << std::endl;
}


void Brain::showIdeas() const
{
    std::cout
        << BG_VIOLET500 BOLD GRAY100 "🧠 Looking into brain ..." RESET
        << std::endl;

    if(this->_ideas[0] == "")
    {
        std::cout
            << YELLOW300 " It's soo empty here 😶" << RESET << std::endl;
        return ; 
    }

    for (int i = 0; this->_ideas[i] != "" && i < MAX_IDEAS; i++)
    {
        std::cout
            << GRAY500 << i + 1 << ". " 
            << YELLOW300 "💡 " << this->_ideas[i] << RESET << std::endl;
    }
}
