/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:23 by escura            #+#    #+#             */
/*   Updated: 2024/08/13 15:49:01 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void test_fragtrap(){

    std::cout << "\n\nTest FragTrap\n\n" << std::endl;

    FragTrap bob("Bob");
    std::cout << std::endl;

    bob.info();
    bob.highFivesGuys();

    std::cout << std::endl;
}

void test_fragtrap2(){
    
        std::cout << "\n\nTest FragTrap\n\n" << std::endl;
    
        FragTrap bob("Bob");
        FragTrap bob2(bob);
        FragTrap bob3 = bob;
        FragTrap bob4;
        bob4 = bob;
        std::cout << std::endl;
    
        bob.attack("Bob");

        bob.info();
        bob2.info();
        bob3.info();
        bob4.info();
        bob.highFivesGuys();
    
        std::cout << std::endl;
}

int main()
{
    test_fragtrap();
    test_fragtrap2();
        
    return (0);
}