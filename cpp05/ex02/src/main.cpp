/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 18:10:56 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}

static void test_title(std::string title){
    std::cout 
        << "\n\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n\n" 
        << std::endl;
}

void test_shrubbery(){
    test_title("TEST SHRUBBERY");

    try{
        ShrubberyCreationForm shrubbery("home");
        Bureaucrat tobby("Tobby", 145);
        Bureaucrat paulo("Paulo", 137);
        Bureaucrat ellen("Ellen", 33);
        nl();
        tobby.signForm(shrubbery);
        paulo.signForm(shrubbery);
        ellen.signForm(shrubbery);
        nl();
        tobby.executeForm(shrubbery);
        paulo.executeForm(shrubbery);
        ellen.executeForm(shrubbery);
        nl();
    }catch(const std::exception &e){
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

void test_robotomy(){
    test_title("TEST ROBOTOMY");

    try{
        AForm *robotomy = new RobotomyRequestForm("robot");
        Bureaucrat tobby("Tobby", 145);
        Bureaucrat paulo("Paulo", 137);
        Bureaucrat ellen("Ellen", 33);
        nl();
        tobby.signForm(*robotomy);
        paulo.signForm(*robotomy);
        ellen.signForm(*robotomy);
        nl();
        tobby.executeForm(*robotomy);
        paulo.executeForm(*robotomy);
        nl();
        ellen.executeForm(*robotomy);
        ellen.executeForm(*robotomy);
        ellen.executeForm(*robotomy);
        ellen.executeForm(*robotomy);
        nl();

        delete robotomy;
    }catch(const std::exception &e){
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

void test_presidential(){
    test_title("TEST PRESIDENTIAL");

    try{
        PresidentialPardonForm presidential;
        Bureaucrat tobby("Tobby", 145);
        Bureaucrat paulo("Paulo", 20);
        Bureaucrat ellen("Ellen", 2);
        nl();
        tobby.signForm(presidential);
        nl();
        tobby.executeForm(presidential);
        paulo.executeForm(presidential);
        nl();
        ellen.executeForm(presidential);
        nl();
    }catch(const std::exception &e){
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

int main(){
    srand(time(NULL));

    test_shrubbery();
    test_robotomy();
    test_presidential();

    nl();
    return 0;
}
