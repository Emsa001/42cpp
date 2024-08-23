/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:56:54 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 22:44:53 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(const std::string &type);
        Cat(const Cat &src);
        Cat &operator=(const Cat &src);

        virtual ~Cat();
        
        // functions
        void makeSound(void) const;
        Brain *getBrain();
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const std::string &type);
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &src);

        virtual ~WrongCat();
        
        // functions
        void makeSound(void) const;
};

#endif