/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:55:50 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 16:52:46 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Thomas"), _grade(150)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Parametrical Constructor called: " BOLD LIME400 << _name
        << RESET << std::endl;

    if (_grade > MIN_GRADE)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    if (_grade < MAX_GRADE)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Copy Constructor called" << std::endl;

    Bureaucrat::operator=(src);
}

Bureaucrat::~Bureaucrat()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " Bureaucrat" RESET " "
        << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_grade = src._grade;

    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade(int value){
    if(this->_grade - value < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    
    this->_grade -= value;
    std::cout
        << BG_GREEN500 "[  GRADE UP   ]" RESET
        << BLUE400 " Bureaucrat" RESET " "
        << "Grade incremented by " BOLD GREEN400 << value << RESET " to " BOLD BLUE400 << this->_grade 
        << RESET << std::endl;
}

void Bureaucrat::decrementGrade(int value){
    if(this->_grade + value > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();

    this->_grade += value;

    std::cout
        << BG_RED500 "[ GRADE DOWN  ]" RESET
        << BLUE400 " Bureaucrat" RESET " "
        << "Grade decremented by " BOLD RED400 << value << RESET " to " BOLD BLUE400 << this->_grade 
        << RESET << std::endl;
}

void Bureaucrat::signForm(Form &form){
    try{
        form.beSigned(*this);

        std::cout
            << BG_PURPLE500 "[ SIGN A FORM ]" RESET " "
            << BLUE400 << this->getName()
            << RESET " signed "
            << TEAL400 << form.getName()
            << RESET << std::endl;

    } catch (const std::exception &e) {
        std::cout
            << BG_PURPLE500 "[ SIGN A FORM ]" RESET " "
            << BLUE400 << this->getName()
            << RESET " couldn't sign " TEAL400 << form.getName() 
            << RESET " because " RED400 << e.what()
            << RESET << std::endl;
    }
}

// exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat *src)
{
    out
        << BG_BLUE500 "[  BURE INFO  ]" RESET
        << " Name: " BOLD PINK300 << src->getName() 
        << RESET ", Grade: " BOLD PINK300 << src->getGrade() 
        << RESET;

	return (out);
}