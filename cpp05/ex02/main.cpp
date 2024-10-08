/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/08 17:22:18 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void nl(){
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
        std::cerr << e.what() << std::endl;
    }
}

void test_gradetoolow(){

    test_title("TEST GRADE TOO LOW");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 15);
        nl();

        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void test_gradetoohigh(){

    test_title("TEST GRADE TOO HIGH");

    try {
        Form veryGermanForm("VeryGermanForm", 10, 20);
        Bureaucrat tobby("Tobby", 5);

        tobby.signForm(veryGermanForm);
        nl();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

int main(){

    test_correct();
    test_gradetoolow();
    test_gradetoohigh();

    nl();
    return 0;
}
