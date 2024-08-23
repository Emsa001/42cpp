/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:48 by escura            #+#    #+#             */
/*   Updated: 2024/08/15 14:17:27 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

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

#include "ClapTrap.hpp"

// https://en.wikipedia.org/wiki/Virtual_inheritance
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ScavTrap &operator=(const ScavTrap &src);
        virtual ~ScavTrap();

        void attack(std::string const &target);
        void guardGate();
};

#endif