/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:52 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:05:53 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(const std::string &name);
        ~Zombie();

		void setName(std::string name);
        void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif
