/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 17:38:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}
static void test_title(std::string title)
{
    std::cout
        << "\n\n" BG_STONE200 GRAY900 "[ " BOLD << title << RESET BG_STONE200 GRAY900 " ]" RESET "\n\n"
        << std::endl;
}

void test_subject()
{
    test_title("TEST SUBJECT");

    try
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        nl();

        Bureaucrat b("Bender", 1);
        b.signForm(*rrf);
        nl();
        b.executeForm(*rrf);
        nl();

        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

void test_all_forms(){
    test_title("TEST ALL FORMS");

    try
    {
        Intern tobby;
        AForm *veryGermanForm;
        AForm *veryPolishForm;
        AForm *veryAmericanForm;
        nl();
        
        veryGermanForm = tobby.makeForm("shrubbery creation", "Boo");
        nl();
        veryPolishForm = tobby.makeForm("robotomy request", "Clyde");
        nl();
        veryAmericanForm = tobby.makeForm("presidential pardon", "Lincoln Burrows");
        nl();

        Bureaucrat b("Bender", 1);
        nl();
        b.signForm(*veryGermanForm);
        b.executeForm(*veryGermanForm);
        nl();

        delete veryGermanForm;
        delete veryPolishForm;
        delete veryAmericanForm;
    }
    catch (const std::exception &e)
    {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
}

int main()
{
    srand(time(NULL));

    test_subject();
    test_all_forms();

    nl();
    return 0;
}
