/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:56:54 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 22:42:45 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/Animal.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(const std::string type);
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);

        virtual ~Dog();

        // functions
        void makeSound(void) const;
        Brain *getBrain();
};

#endif