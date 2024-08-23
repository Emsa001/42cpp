/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/08/22 19:57:46 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void nl(){
    std::cout << std::endl;
}

int main(){
    try {
        Bureaucrat Tobby("Tobby", 50);
        Tobby.incrementGrade(10);
        std::cout << &Tobby << std::endl;
        Tobby.decrementGrade(10);
        std::cout << &Tobby << std::endl;
        Tobby.incrementGrade(30);
        std::cout << &Tobby << std::endl;
        Tobby.incrementGrade(30);
        std::cout << &Tobby << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    nl();

    try {
        Bureaucrat Bommy("Bobby", 0);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    nl();

    try {
        Bureaucrat Pommy("Kobby", 151);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    nl();

    return 0;
}
