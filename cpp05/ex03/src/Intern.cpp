/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:09:56 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 17:34:10 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Intern" RESET " "
        << "Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Intern" RESET " "
        << "Copy Constructor called" << std::endl;

    Intern::operator=(src);
}

Intern::~Intern()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " Intern" RESET " "
        << "Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN600 "[  OPERATOR   ]" RESET
        << LIME400 " Intern" RESET " "
        << "Copy Assignment operator called" << std::endl;

    return *this;
}

const char *Intern::UnknownFormException::what() const throw()
{
    return ("I don't know how to form this form");
}

// Static member functions definitions
AForm *Intern::createShrubberyForm(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
    AForm *(*formPointers[3])(std::string target) = {
        Intern::createShrubberyForm,
        Intern::createRobotomyForm,
        Intern::createPresidentialPardonForm};
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == type)
        {
            std::cout
                << BG_BLUE600 "[   FORMED    ]" RESET
                << BLUE400 " Intern" RESET " "
                << "Formed a " << type << " form" << std::endl;
            
            return formPointers[i](target);
        }
    }

    throw Intern::UnknownFormException();
}