/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:23 by escura            #+#    #+#             */
/*   Updated: 2024/08/15 14:05:42 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void test_claptrap(){

    std::cout << "\n\nTest ClapTrap\n\n" << std::endl;

    ClapTrap spongebob("SpongeBob");
    ClapTrap patric("Patric");
    ClapTrap skalmar("Skalmar"); 

    spongebob.attack("Patric");
    
    patric.beRepaired(5);
    patric.attack("SpongeBob");

    spongebob.info();
    patric.info();

    spongebob.attack("Patric");

    skalmar.takeDamage(10);
    skalmar.attack("SpongeBob");

    skalmar.info();
}

void test_scavtrap(){

    std::cout << "\n\nTest ScavTrap\n\n" << std::endl;

    // create objects
    ScavTrap spongebob("SpongeBob");
    ScavTrap patric("Patric");
    ScavTrap skalmar("Skalmar"); 

    // print info
    std::cout << std::endl;
    spongebob.info();
    patric.info();
    std::cout << std::endl;

    // test attack
    std::cout << std::endl;
    spongebob.attack("Patric");
    patric.beRepaired(5);
    patric.attack("SpongeBob");
    std::cout << std::endl;

    // print info
    std::cout << std::endl;
    spongebob.info();
    patric.info();
    std::cout << std::endl;

    // test gate
    std::cout << std::endl;
    spongebob.guardGate();
    skalmar.takeDamage(10);
    skalmar.guardGate();
    std::cout << std::endl;

    // print info
    std::cout << std::endl;
    spongebob.info();
    patric.info();
    skalmar.info();
    std::cout << std::endl;
}

void test_multiple(){

    std::cout << "\n\nTest multiple objects\n\n" << std::endl;

    ClapTrap spongebob("SpongeBob");
    ScavTrap patric("Patric");
    ClapTrap skalmar("Skalmar"); 

    spongebob.attack("Patric");
    
    patric.beRepaired(5);
    patric.attack("SpongeBob");

    spongebob.info();
    patric.info();

    spongebob.attack("Patric");

    skalmar.takeDamage(10);
    skalmar.attack("SpongeBob");

    skalmar.info();
}

int main()
{
    // test_claptrap();
    test_scavtrap();
    // test_multiple();
        
    return (0);
}