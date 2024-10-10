/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:44:45 by escura            #+#    #+#             */
/*   Updated: 2024/10/08 17:57:17 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdbool.h>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
    public:
        Form();
        Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &src);
        ~Form();

        Form &operator=(const Form &src); 

        // getters
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        // public members
        void beSigned(const Bureaucrat &bureaucrat);

    // exceptions
    class AlreadySignedException : public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };
};


#endif