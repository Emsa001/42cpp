/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:04 by escura            #+#    #+#             */
/*   Updated: 2024/10/14 19:49:29 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &src);

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade(int value);
        void decrementGrade(int value);

    // exceptions
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };

};

std::ostream	&operator<<(std::ostream &out, Bureaucrat *src);