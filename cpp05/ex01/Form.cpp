#include "Form.hpp"
#include "Colors.hpp"

Form::Form() : _name("default"), _gradeToSign(1), _gradeToExecute(1), _signed(false)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Default Constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{

    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Parametrical Constructor called: " BOLD LIME400 << name
        << RESET << std::endl;

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " Form" RESET " "
        << "Copy Constructor called" << std::endl;
}

Form::~Form()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR ]" RESET
        << RED400 " Form" RESET " "
        << "Destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR  ]" RESET
        << LIME400 " Form" RESET " "
        << "Copy Assignment operator called" << std::endl;

    this->_signed = src._signed;

    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

void Form::beSigned()
{
    this->_signed = true;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

// exceptions

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low to sign");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high to sign");
}

const char *Form::AlreadySigned::what(void) const throw()
{
    return ("Already signed");
}

std::ostream &operator<<(std::ostream &out, Form *src)
{
    out
        << BG_BLUE600 "[    INFO     ]" RESET
        << BLUE400 " Form" RESET " "
        << "Name: " BOLD PINK300 << src->getName()
        << RESET ", Grade to sign: " BOLD PINK300 << src->getGradeToSign()
        << RESET ", Grade to execute: " BOLD PINK300 << src->getGradeToExecute()
        << RESET;

    return (out);
}