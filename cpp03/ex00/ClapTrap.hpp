/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:48 by escura            #+#    #+#             */
/*   Updated: 2024/08/15 14:04:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define ORANGE "\033[38;5;208m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define AQUA "\033[38;5;14m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include <iostream>

#define MAX_CLAPTRAPS 20

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitpoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        
        static ClapTrap *claptraps[MAX_CLAPTRAPS];

        ClapTrap *getClaptrap(const std::string &name) const;
        void putClaptrap(ClapTrap *claptrap);
        void removeClaptrap(ClapTrap *claptrap);

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ClapTrap &operator=(const ClapTrap &src);
        ~ClapTrap();
        

        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void info() const;
        bool verify() const;
};

#endif