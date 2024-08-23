/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:56 by escura            #+#    #+#             */
/*   Updated: 2024/08/02 22:15:24 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    this->_levels[0] = "debug";
    this->_levels[1] = "info";
    this->_levels[2] = "warning";
    this->_levels[3] = "error";

    this->_functions[0] = &Harl::debug;
    this->_functions[1] = &Harl::info;
    this->_functions[2] = &Harl::warning;
    this->_functions[3] = &Harl::error;

    std::cout << BLUE"🔊 Harl is ready to complain" << RESET << std::endl;
}

Harl::~Harl()
{
    std::cout << PURPLE"🔇 Harl is done complaining" << RESET << std::endl;
}

void Harl::debug(void)
{
    std::cout
        << AQUA"🪲  Debug messages sucks. In pizza 🍕, we trust!" 
        << RESET
        << std::endl;
}

void Harl::info(void)
{
    std::cout 
        << GREEN"ℹ️  Pizza 🍕 is not a trend, it's a way of life!" 
        << RESET 
        << std::endl;
}

void Harl::warning(void)
{
    std::cout 
        << YELLOW"❗️ You can't make everyone happy. You're not a pizza 🍕." 
        << RESET  
        << std::endl;
}

void Harl::error(void)
{
    std::cout 
        << RED"🚨 If pizza 🍕 can't fix it, it's a serious problem." 
        << RESET
        << std::endl;
}

void Harl::unknown(std::string level)
{
    std::cout 
        << "🤷 I don't know what to do with, did you try to add a tomato sauce 🍅 to it? " 
        << PURPLE 
        << "tomato-" + level 
        << RESET 
        << std::endl;
    return;
}

void Harl::complain(std::string level)
{
    int i = 0;
    for(i = 0; i < 4; i++){
        if(this->_levels[i] == level){
            (this->*_functions[i])();
            return ;
        }
    }
    Harl::unknown(level);
}
