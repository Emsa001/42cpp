/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:44:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 17:02:34 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "Steve", 72, 45)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " RobotomyRequestForm" RESET " "
        << "Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{

    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " RobotomyRequestForm" RESET " "
        << "Parameter Constructor called with type: "
        << PINK300 << target
        << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " RobotomyRequestForm" RESET " "
        << "Copy Constructor called" << std::endl;

    this->operator=(src);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " RobotomyRequestForm" RESET " "
        << "Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
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
void RobotomyRequestForm::executeImpl(Bureaucrat const &executor) const
{
    (void)executor;

    std::cout
        << BG_GRAY700 "[  ROBOTOMY   ]" RESET " "
        << GRAY300 "Drrr "
        << GRAY400 "Drrrr "
        << GRAY500 "Drrrrrr "
        << RESET << std::endl;

    bool robotomized = rand() % 2;

    if (robotomized)
        std::cout
            << BG_GRAY700 "[  ROBOTOMY   ]" RESET " "
            << BLUE400 << this->getTarget() << RESET " "
            << GRAY400 "Robotomized "
            << GREEN400 "successfully"
            << RESET << std::endl;
    else
        std::cout
            << BG_GRAY700 "[  ROBOTOMY   ]" RESET " "
            << BLUE400 << this->getTarget() << RESET " "
            << GRAY400 "Robotomized "
            << RED400 "failed"
            << RESET << std::endl;
}