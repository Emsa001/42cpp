/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:36 by escura            #+#    #+#             */
/*   Updated: 2024/10/10 18:11:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}
int main(){
    Bureaucrat *Tobby;
    
    try {
        Tobby = new Bureaucrat("Tobby", 50);
        Tobby->incrementGrade(10);
        std::cout << Tobby << std::endl;
        Tobby->decrementGrade(10);
        std::cout << Tobby << std::endl;
        Tobby->incrementGrade(30);
        std::cout << Tobby << std::endl;
        Tobby->incrementGrade(30);
        std::cout << Tobby << std::endl;
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    delete Tobby;
    nl();

    try {
        Bureaucrat Bommy("Bobby", 0);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    nl();

    try {
        Bureaucrat Pommy("Kobby", 151);
        nl();
    } catch (const std::exception &e) {
        std::cerr
            << BG_RED500 "[  EXCEPTION  ]" RESET " "
            << RED400 << e.what()
            << RESET << std::endl;
    }
    nl();

    return 0;
}
