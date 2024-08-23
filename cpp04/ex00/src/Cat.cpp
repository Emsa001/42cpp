/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:45:08 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 21:18:40 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Constructors and destructors

Cat::Cat() : Animal("Cat")
{
    std::cout
        << ORANGE300 "🐱 Cat" RESET " "
        << "Default Constructor called" << std::endl;
}

Cat::Cat(const std::string &type): Animal(type)
{
    std::cout
        << ORANGE300 "🐱 Cat" RESET " "
        << "Parametrical Constructor called with type: "
        << AMBER200 << type << RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout
        << ORANGE300 "🐱 Cat" RESET " "
        << "Copy Constructor called" << std::endl;
    
    Animal::operator=(src);
}

Cat::~Cat()
{
    std::cout
        << ORANGE300 "🪦 Cat" RESET " "
        << "Desctructor called" << std::endl;
}

// Operators

Cat &Cat::operator=(const Cat &src)
{
    if (this == &src)
        return *this;

    std::cout
        << ORANGE300 "🐱 Cat" RESET " "
        << "Copy Assignment Constructor called" << std::endl;

    this->type = src.type;
    return *this;
}

// Public functions

void Cat::makeSound() const
{
    std::cout
        << ORANGE300 "💭 " << this->getType() << RESET " "
        << "Says: " << AMBER200 "Mew Mew Mew" << RESET << std::endl;
}



/*

 __        ______   ___  _   _  ____  ____    _  _____ 
 \ \      / /  _ \ / _ \| \ | |/ ___|/ ___|  / \|_   _|
  \ \ /\ / /| |_) | | | |  \| | |  _| |     / _ \ | |  
   \ V  V / |  _ <| |_| | |\  | |_| | |___ / ___ \| |  
    \_/\_/  |_| \_\\___/|_| \_|\____|\____/_/   \_\_|  
                                                       

*/



// Constructors and destructors

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout
        << ORANGE400 "🐱 WrongCat" RESET " "
        << "Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type)
{
    std::cout
        << ORANGE400 "🐱 WrongCat" RESET " "
        << "Parametrical Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout
        << ORANGE400 "🐱 WrongCat" RESET " "
        << "Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout
        << ORANGE400 "🪦 WrongCat" RESET " "
        << "Desctructor called" << std::endl;
}

// Operators

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    if (this == &src)
        return *this;

    std::cout
        << ORANGE400 "🐱 WrongCat" RESET " "
        << "Copy Assignment Operator called" << std::endl;

    WrongCat::operator=(src);
    return *this;
}

// Public functions

void WrongCat::makeSound() const
{
    std::cout
        << ORANGE400 "💭 " << this->getType() << RESET " "
        << "Says: " << AMBER300 "Bew Bew Bew" << RESET << std::endl;
}