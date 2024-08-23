/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:24 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:23:34 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void testHeapZombie(const std::string& name) {
    Zombie* heapZombie = newZombie(name);
    if (heapZombie == NULL) {
        std::cout << "❌ Test failed: newZombie() didn't allocate memory on the heap for " << name << std::endl;
    } else {
        std::cout << "✅ Test passed: newZombie() allocated memory on the heap for " << name << std::endl;
    }
    delete heapZombie;
}

int main() {
    Zombie ZombieStefan("Stefan");
    ZombieStefan.announce();

    Zombie FooZombie("Foo");
    FooZombie.announce();

    randomChump("Paulo");
    randomChump("Beqa");

    std::cout << std::endl;
    testHeapZombie("Heap");
    testHeapZombie("Heap2");
    std::cout << std::endl;

    
    return 0;
}
