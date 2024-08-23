/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:24:41 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 21:02:48 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./AMateria.hpp"

#define INVENTORY_SIZE 4

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria *_inventory[INVENTORY_SIZE]; 
               
    public:
        Character();
        Character(std::string const &name);
        Character(Character const &src);
        ~Character();

        Character &operator=(Character const &src);

        // public members
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
#endif