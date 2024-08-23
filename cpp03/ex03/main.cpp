/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:23 by escura            #+#    #+#             */
/*   Updated: 2024/08/16 17:15:41 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void test_duamondtrap(){

    std::cout << "\n\nTest DiamondTrap\n\n" << std::endl;

    DiamondTrap diamondBob("diamondBob");
    DiamondTrap diamondPatric("diamondPatric");
    
    std::cout << std::endl;
    diamondBob.info();
    std::cout << std::endl;

    diamondBob.attack("diamondPatric");
    diamondBob.takeDamage(10);
    diamondBob.beRepaired(5);
    diamondBob.guardGate();
    diamondBob.highFivesGuys();

    std::cout << std::endl;
    diamondBob.info();
    std::cout << std::endl;
}

void test_virtual(){
    DiamondTrap* ptr = new DiamondTrap();
    DiamondTrap diamondBob(*ptr);

    ptr->info();

    delete ptr;
}

int main()
{
    // test_duamondtrap();
    test_virtual();
        
    return (0);
}