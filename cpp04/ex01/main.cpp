/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:23:07 by escura            #+#    #+#             */
/*   Updated: 2024/08/18 23:26:32 by escura           ###   ########.fr       */
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

    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;
    delete j;
    std::cout << std::endl;
    delete i;
}

void test_brain_dog(){
    test_title(VIOLET800"TEST BRAIN DOG");

    Dog* smartDog = new Dog();
    std::cout << std::endl;
    Dog* stupidDog = new Dog();
    std::cout << std::endl;

    smartDog->getBrain()->putIdea(" 2 + 2 = 5? ");
    smartDog->getBrain()->showIdeas();
    std::cout << std::endl;

    *stupidDog = *smartDog;
    std::cout << std::endl;

    stupidDog->getBrain()->showIdeas();
    std::cout << std::endl;

    delete smartDog;
    delete stupidDog;
}

void test_brain_cat(){
    test_title(VIOLET800"TEST BRAIN CAT");

    Cat* smartCat = new Cat();
    std::cout << std::endl;
    Cat* stupidCat = new Cat();
    std::cout << std::endl;

    smartCat->getBrain()->putIdea(" Me want milk 🐱💅 ");
    smartCat->getBrain()->showIdeas();
    std::cout << std::endl;

    *stupidCat = *smartCat;
    std::cout << std::endl;

    stupidCat->getBrain()->showIdeas();
    std::cout << std::endl;

    delete smartCat;
    delete stupidCat;
}

void test_crazysmart(){
    test_title(VIOLET800"TEST CRAZY SMART");

    Dog crazySmartDog;
    std::cout << std::endl;

    const char* quotes[] = {
        "The key to winning is not losing.",
        "If you don't know where you're going, any road will confuse you.",
        "Success is 90% effort and 10% everything else.",
        "The secret to being unpredictable is to always do the unexpected.",
        "To be great, you must be better than everyone who isn't great.",
        "If you want to find yourself, look in a mirror.",
        "The only thing you need to know is that knowledge is overrated.",
        "To be truly free, you must first chain yourself to freedom.",
        "The future is tomorrow's yesterday.",
        "Wisdom is knowing that you don't know what you think you know."
    };

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            crazySmartDog.getBrain()->putIdea(quotes[i]);
        }
    }

    crazySmartDog.getBrain()->putIdea("ME WANT MORE POWERRR 😈😈😈");

    std::cout << std::endl;
    crazySmartDog.getBrain()->showIdeas();
    std::cout << std::endl;
}

int main() {
    test_subject();
    test_brain_dog();
    test_brain_cat();
    test_crazysmart();
    return 0;
}
