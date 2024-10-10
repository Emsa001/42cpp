/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 18:42:06 by escura           ###   ########.fr       */
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
    test_title("   CORRECT   ");
    Bureaucrat *Tobby;
    
    try {
        Tobby = new Bureaucrat("Tobby", 50);
        nl();
        Tobby->incrementGrade(10);
        std::cout << Tobby << std::endl;
        Tobby->decrementGrade(10);
        std::cout << Tobby << std::endl;
        Tobby->incrementGrade(30);
        std::cout << Tobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    delete Tobby;
}

void test_too_low(){
    test_title("GRADE TOO LOW");
    
    try{
        Bureaucrat bobby("Bobby", 151);
        nl();
        std::cout << &bobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }

    nl();

    Bureaucrat *Tobby;
    try {
        Tobby = new Bureaucrat("Tobby", 50);
        nl();
        Tobby->decrementGrade(101);
        std::cout << Tobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    delete Tobby;
}

void test_too_high(){
    test_title("GRADE TO HIGH");

    try{
        Bureaucrat bobby("Bobby", 0);
        nl();
        std::cout << &bobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }

    nl();

    Bureaucrat *Tobby;
    try {
        Tobby = new Bureaucrat("Tobby", 50);
        nl();
        Tobby->incrementGrade(50);
        std::cout << Tobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    delete Tobby;
}

int main(){
    test_correct();
    test_too_low();
    test_too_high();

    nl();
    return 0;
}
