/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:43:42 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 16:37:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Colors.hpp"
#include "./Character.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(AMateria const &src);
        virtual ~AMateria();

        AMateria &operator=(AMateria const &src); 
    
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
        virtual std::string const &getType() const; // Returns the materia type
};

#endif