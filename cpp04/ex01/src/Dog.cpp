/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:45:08 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 22:55:19 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Constructors and destructors

Dog::Dog() : Animal("Dog")
{
    std::cout
        << BLUE300 "🐶 Dog" RESET " "
        << "Default Constructor called" << std::endl;

    this->_brain = new Brain();
}

Dog::Dog(const std::string type) : Animal(type)
{
    std::cout
        << BLUE300 "🐶 Dog" RESET " "
        << "Parametrical Constructor called with type: "
        << SKY300 << type << RESET << std::endl;

    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout
        << BLUE300 "🐶 Dog" RESET " "
        << "Copy Constructor called" << std::endl;

    this->_brain = new Brain();
    Dog::operator=(src);
}

Dog::~Dog()
{
    std::cout
        << BLUE300 "🪦 Dog" RESET " "
        << "Desctructor called" << std::endl;

    delete this->_brain;
}

// Operators

Dog &Dog::operator=(const Dog &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BLUE300 "🐶 Dog" RESET " "
        << "Copy Assignment Operator called" << std::endl;

    this->type = src.type;
    *this->_brain = *src._brain;

    return *this;
}

// Public functions

void Dog::makeSound() const
{
    std::cout
        << BLUE300 "💭 " << this->getType() << RESET " "
        << "Says: " << SKY300 "Woof Woof Woof" << RESET << std::endl;
}

Brain *Dog::getBrain()
{
    return this->_brain;
}