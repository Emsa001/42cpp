/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:44:45 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 15:48:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdbool.h>
#include "Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        const std::string _target;
        const int _gradeToSign;
        const int _gradeToExecute;
        bool _isSigned;
        
    public:
        AForm();
        AForm(const std::string &name, const std::string &target, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &src);
        virtual ~AForm();

        AForm &operator=(const AForm &src); 

        // getters
        std::string getName() const;
        std::string getTarget() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        // public members
        void beSigned(Bureaucrat const  &bureaucrat);
        void execute(Bureaucrat const &executor) const;
        virtual void executeImpl(Bureaucrat const &executor) const = 0;

    // exceptions
    class AlreadySignedException : public std::exception{
        public:
            const char* what() const throw();
    };

    class NotSignedException : public std::exception{
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

std::ostream	&operator<<(std::ostream &out, AForm *src);

#endif