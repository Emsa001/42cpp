/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 18:10:43 by escura           ###   ########.fr       */
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
        b.executeForm(*rrf);
        nl();
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

    nl();
    return 0;
}
