/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:51:13 by escura            #+#    #+#             */
/*   Updated: 2024/10/08 17:56:42 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :  _name("Unknown AForm"), 
                _gradeToSign(10),
                _gradeToExecute(10), 
                _isSigned(false)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " AForm" RESET " "
        << "Default Constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute):
    _name(name), 
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute), 
    _isSigned(false)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " AForm" RESET " "
        << "Parametrical Constructor called: " BOLD LIME400 << _name
        << RESET << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name),
                              _gradeToSign(src._gradeToSign),
                              _gradeToExecute(src._gradeToExecute),
                              _isSigned(src._isSigned)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " AForm" RESET " "
        << "Copy Constructor called" << std::endl;
}

AForm::~AForm(){
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " AForm" RESET " "
        << "Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
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
std::string AForm::getName() const {
    return this->_name;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}


// public memebts
void AForm::beSigned(const Bureaucrat &bureaucrat){
    if(this->getIsSigned())
        throw AForm::AlreadySignedException();
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    if(bureaucrat.getGrade() < this->getGradeToSign())
        throw AForm::GradeTooHighException();
    
    this->_isSigned = true;
}

const char *AForm::AlreadySignedException::what() const throw()
{
    return ("Already Signed");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &out, AForm *src)
{
    out
        << BG_BLUE600 "[    INFO     ]" RESET
        << BLUE400 " AForm"
        << RESET "Name: " BOLD PINK300 << src->getName() 
        << RESET ", Grade to sign: " BOLD PINK300 << src->getGradeToSign() 
        << RESET ", Grade to execute: " BOLD PINK300 << src->getGradeToExecute() 
        << RESET ", Signed: " BOLD PINK300 << src->getIsSigned() 
        << RESET << std::endl;

	return (out);
}