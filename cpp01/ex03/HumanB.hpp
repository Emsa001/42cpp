/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:20 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:06:23 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB{
    private:
        std::string _name;
        Weapon *_weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif