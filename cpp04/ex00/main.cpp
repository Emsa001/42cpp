/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:23:07 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 21:23:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

static void test_title(std::string title){
    std::cout 
        << "\n\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n\n" 
        << std::endl;
}

void test_subject() {
    test_title(VIOLET900"TEST SUBJECT");

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;
}

void test_wrongAnimal() {
    test_title(PURPLE600"TEST WRONG_ANIMAL");

    const WrongAnimal *paulo = new WrongCat();
    paulo->makeSound();
    std::cout << std::endl;

    const WrongCat *beqa = new WrongCat();
    beqa->makeSound();
    std::cout << std::endl;

    delete paulo;
    delete beqa;
}

void test_wierd() {
    test_title(VIOLET600"TEST WIERD");

    Animal *paulo = new Dog();
    Animal beqa = *paulo; // beqa isn't a Dog
    std::cout << std::endl;

    Animal *paulo2 = new Dog();
    Animal *beqa2 = paulo2;
    std::cout << std::endl;

    std::cout << TEAL300"Beqa" RESET " is type: " TEAL500 << beqa.getType() << RESET << std::endl;
    std::cout << TEAL300"Beqa2" RESET " is type: " TEAL500 << beqa2->getType() << RESET << std::endl;

    std::cout << std::endl;
    beqa.makeSound();
    beqa2->makeSound();

    std::cout << std::endl;
    delete paulo;
    delete paulo2;

    std::cout << std::endl;
    beqa.makeSound(); // should print "💭 Animal Says: wingardium leviosa"
}

void test_copy_constructor() {
    test_title(INDIGO600"TEST COPY CONSTRUCTOR");

    Dog *puppy = new Dog();
    Dog *poppy = new Dog(*puppy);
    std::cout << std::endl;

    std::cout << TEAL300"Puppy" RESET " is type: " TEAL500 << puppy->getType() << RESET << std::endl;
    std::cout << TEAL300"Poppy" RESET " is type: " TEAL500 << poppy->getType() << RESET << std::endl;
    std::cout << std::endl;

    puppy->makeSound();
    poppy->makeSound();
    std::cout << std::endl;

    delete puppy;
    delete poppy;
}

void test_assignment() {
    test_title(BLUE600 "TEST ASSIGNMENT");

    Animal *animal1 = new Dog();
    Animal *animal2 = new Cat();
    std::cout << std::endl;

    std::cout 
        << "Before assignment," TEAL300 " Animal2" RESET " is type: " TEAL500 
        << animal2->getType() << RESET << std::endl;

    *animal2 = *animal1;
    std::cout << std::endl;

    animal1->makeSound();
    animal2->makeSound();
    std::cout << std::endl;

    delete animal1;
    delete animal2;
}

void test_virtual_destructor() {
    test_title(SKY600"TEST VIRTUAL DESTRUCTOR");

    Animal *animal1 = new Dog();
    Animal *animal2 = new Cat();
    std::cout << std::endl;

    delete animal1; // Should call Dog's destructor
    delete animal2; // Should call Cat's destructor
}

void test_multiple_animals() {
    test_title(CYAN600"TEST MULTIPLE ANIMALS");

    Animal *animals[3];
    animals[0] = new Dog();
    std::cout << std::endl;
    animals[1] = new Cat();
    std::cout << std::endl;
    animals[2] = new Animal();
    std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << std::endl;
        animals[i]->makeSound();
        delete animals[i];
    }
}

void test_different_assignments() {
    test_title(TEAL600"TEST DIFFERENT ASSIGNMENTS");

    Dog dog;
    std::cout << std::endl;
    Animal *animal = new Cat();
    std::cout << std::endl;

    std::cout << "Before assignment," TEAL300" Animal" RESET " is type: " TEAL500 << animal->getType()  << RESET<< std::endl;
    
    *animal = dog; // Test assignment of different types

    std::cout << "After assignment," TEAL300" Animal" RESET " is type: " TEAL500 << animal->getType() << RESET << std::endl;
    std::cout << std::endl;

    animal->makeSound();
    std::cout << std::endl;
    
    delete animal;
}

int main() {
    test_subject();
    test_wrongAnimal();
    test_wierd();
    test_copy_constructor();
    test_assignment();
    test_virtual_destructor();
    test_multiple_animals();
    test_different_assignments();
    return 0;
}
