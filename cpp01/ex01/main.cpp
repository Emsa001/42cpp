/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:45 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:27:12 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie ZombieStefan("Stefan");
    ZombieStefan.announce();

    Zombie *horde = zombieHorde(5, "Frank");
    for(int i = 0; i < 5; i++){
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}
