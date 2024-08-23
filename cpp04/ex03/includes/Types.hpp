/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:47:08 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 16:36:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCRETE_HPP
#define CONCRETE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice();
        Ice(Ice const &src);
        ~Ice();

        Ice &operator=(Ice const &src); 
        AMateria* clone() const;
        void use(ICharacter &target);
};

class Cure : public AMateria {

    public:
        Cure();
        Cure(Cure const &src);
        ~Cure();

        Cure &operator=(Cure const &src); 
        AMateria* clone() const;
        void use(ICharacter &target);
};


#endif