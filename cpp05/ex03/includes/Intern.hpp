/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:03:33 by escura            #+#    #+#             */
/*   Updated: 2024/10/11 17:30:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{
    private:
        static AForm* createShrubberyForm(const std::string target);
        static AForm* createRobotomyForm(const std::string target);
        static AForm* createPresidentialPardonForm(const std::string target);
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();

        Intern &operator=(const Intern &src);

        AForm* makeForm(const std::string &type, const std::string &target);

        class UnknownFormException : public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif