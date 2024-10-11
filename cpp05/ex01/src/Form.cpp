/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:51:13 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 16:52:55 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :  _name("Unknown Form"), 
                _gradeToSign(10),
                _gradeToExecute(10), 
                _isSigned(false)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Default Constructor called" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute):
    _name(name), 
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute), 
    _isSigned(false)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Parametrical Constructor called: " BOLD LIME400 << _name
        << RESET << std::endl;

    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

Form::Form(const Form &src) : _name(src._name),
                              _gradeToSign(src._gradeToSign),
                              _gradeToExecute(src._gradeToExecute),
                              _isSigned(src._isSigned)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Copy Constructor called" << std::endl;
}

Form::~Form(){
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " Form" RESET " "
        << "Destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET
        << LIME400 " Bureaucrat" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_isSigned = src._isSigned;

    return *this;
}

// getters
std::string Form::getName() const {
    return this->_name;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}


// public memebts
void Form::beSigned(const Bureaucrat &bureaucrat){
    if(this->getIsSigned())
        throw Form::AlreadySignedException();
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    
    this->_isSigned = true;
}

const char *Form::AlreadySignedException::what() const throw()
{
    return ("Already Signed");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &out, Form *src)
{
    out
        << BG_BLUE600 "[  FORM INFO  ]"
        << RESET " Name: " BOLD PINK300 << src->getName() 
        << RESET ", Grade to sign: " BOLD PINK300 << src->getGradeToSign() 
        << RESET ", Grade to execute: " BOLD PINK300 << src->getGradeToExecute() 
        << RESET ", Signed: " BOLD PINK300 << (src->getIsSigned() ? GREEN400"true" : RED400"false")
        << RESET;

	return (out);
}