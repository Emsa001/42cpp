/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:45:08 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 21:08:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Constructors and destructors

Animal::Animal() : type("Animal")
{
    std::cout
        << PINK300 "🐾 Animal" RESET " "
        << "Default Constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout
        << PINK300 "🐾 Animal" RESET " "
        << "Parametrical Constructor called with type: "
        << FUCHSIA300 << type << RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout
        << PINK300 "🐾 Animal" RESET " "
        << "Copy Constructor called" << std::endl;

    Animal::operator=(src);
}

Animal::~Animal()
{
    std::cout
        << PINK300 "🪦 Animal" RESET " "
        << "Destructor called" << std::endl;
}

// Operators

Animal &Animal::operator=(const Animal &src)
{
    if (this == &src)
        return *this;

    std::cout
        << PINK300 "🐾 Animal" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->type = src.type;

    return *this;
}

// Public functions

void Animal::makeSound() const
{
    std::cout
        << PINK300 "💭 Animal" RESET " "
        << "Says: " << FUCHSIA300 "wingardium leviosa" << RESET << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}



/*

 __        ______   ___  _   _  ____    _    _   _ ___ __  __    _    _     
 \ \      / /  _ \ / _ \| \ | |/ ___|  / \  | \ | |_ _|  \/  |  / \  | |    
  \ \ /\ / /| |_) | | | |  \| | |  _  / _ \ |  \| || || |\/| | / _ \ | |    
   \ V  V / |  _ <| |_| | |\  | |_| |/ ___ \| |\  || || |  | |/ ___ \| |___ 
    \_/\_/  |_| \_\\___/|_| \_|\____/_/   \_\_| \_|___|_|  |_/_/   \_\_____|
                                                                            

*/



// Constructors and destructors

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout
        << RED400 "🐾 WrongAnimal" RESET " "
        << "Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout
        << RED400 "🐾 WrongAnimal" RESET " "
        << "Parametrical Constructor called with type: "
        << ROSE500 << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout
        << RED400 "🐾 WrongAnimal" RESET " "
        << "Copy Constructor called" << std::endl;
        
    WrongAnimal::operator=(src);
}

WrongAnimal::~WrongAnimal()
{
    std::cout
        << RED400 "🪦 WrongAnimal" RESET " "
        << "Desctructor called" << std::endl;
}

// Operators

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this == &src)
        return *this;

    this->type = src.type;

    std::cout
        << RED400 "🐾 WrongAnimal" RESET " "
        << "Copy Assignment Operator called" << std::endl;

    return *this;
}

// Public functions

void WrongAnimal::makeSound() const
{
    std::cout
        << RED400 "💭 WrongAnimal" RESET " "
        << "Says: " << RED300 "What is wrong anyway?" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}