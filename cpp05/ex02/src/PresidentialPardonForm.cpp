/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:44:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 17:02:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "Lincoln Burrows", 25, 5)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " PresidentialPardonForm" RESET " "
        << "Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " PresidentialPardonForm" RESET " "
        << "Parameter Constructor called with type: "
        << PINK300 << target
        << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " PresidentialPardonForm" RESET " "
        << "Copy Constructor called" << std::endl;

    this->operator=(src);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " PresidentialPardonForm" RESET " "
        << "Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Copy Assignment operator called" << std::endl;

    return *this;
}

// Then your function becomes
void PresidentialPardonForm::executeImpl(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout
        << BG_YELLOW800 "[   PARDON    ]" RESET " "
        << PINK300 BOLD << this->getTarget()
        << RESET " has been pardoned by "
        << PINK300 BOLD "Zafod Beeblebrox"
        << RESET << std::endl;
}