/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 18:38:03 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}

static void test_title(std::string title){
    std::cout 
        << "\n\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n\n" 
        << std::endl;
}

void test_correct(){

    test_title("TEST CORRECT");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 10);
        nl();

        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

void test_alreadySigned(){

    test_title("TEST ALREADY SIGNED");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 10);
        nl();

        tobby.signForm(veryGermanForm);
        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

void test_gradeTooLow(){

    test_title("TEST GRADE TOO LOW");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 15);
        nl();

        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }

}

void test_gradeTooHigh(){

    test_title("TEST GRADE TOO HIGH");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 5);

        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }

}

void test_out_of_bounds(){

    test_title("TEST OUT OF BOUNDS");

    try {
        Form veryGermanForm("LittleGermanForm", 151, 0);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

int main(){

    test_correct();
    test_alreadySigned();
    test_gradeTooLow();
    test_gradeTooHigh();
    test_out_of_bounds();

    nl();
    return 0;
}
