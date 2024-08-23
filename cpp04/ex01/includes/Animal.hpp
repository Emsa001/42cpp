/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:23:31 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 21:31:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"
#include "Colors.hpp"

class Animal
{
    protected:
        std::string type;
    
    public:

        Animal();
        Animal(const std::string &type);
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);

        virtual ~Animal();

        // functions
        virtual void makeSound(void) const;
        std::string getType(void) const;
};

class WrongAnimal
{
    protected:
        std::string type;
    
    public:

        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &src);

        virtual ~WrongAnimal();

        // functions
        void makeSound(void) const;
        std::string getType(void) const;
};


#endif