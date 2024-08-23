/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:41 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:05:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie  {
    private:
        std::string _name;
    public:
        Zombie(const std::string& name);
        ~Zombie();

        void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
