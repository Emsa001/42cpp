/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:23 by escura            #+#    #+#             */
/*   Updated: 2024/08/16 17:17:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main2()
{
    // Create ClapTrap objects
    std::cout << std::endl;
    ClapTrap spongebob("SpongeBob");
    ClapTrap patric("Patric");
    ClapTrap skalmar("Skalmar"); 
    std::cout << std::endl;

    // Attack and repair
    std::cout << std::endl;
    spongebob.attack("Patric");
    patric.beRepaired(5);
    patric.attack("SpongeBob");
    std::cout << std::endl;

    // Info
    std::cout << std::endl;
    spongebob.info();
    patric.info();
    std::cout << std::endl;

    // Take damage
    std::cout << std::endl;
    spongebob.attack("Patric");
    skalmar.takeDamage(10);
    skalmar.attack("SpongeBob");
    std::cout << std::endl;

    // Info
    std::cout << std::endl;
    spongebob.info();
    patric.info();
    skalmar.info();
    std::cout << std::endl;
        
    return (0);
}

int main(){
    ClapTrap spongebob("SpongeBob");
    ClapTrap sponge2(spongebob);
}