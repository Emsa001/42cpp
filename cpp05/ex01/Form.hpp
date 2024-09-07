#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
private:
    const std::string _name;
    const int _gradeToSign;
    const int _gradeToExecute;
    bool _signed;

public:
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &src);
    ~Form();

    Form &operator=(const Form &src);

    void beSigned();
    bool getSigned() const;
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // exceptions
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class AlreadySigned : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form *src);

#endif
