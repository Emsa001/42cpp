/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:23:07 by escura            #+#    #+#             */
/*   Updated: 2024/08/19 11:42:20 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Animal.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Dog.hpp"

static void test_title(std::string title){
    std::cout 
        << "\n\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n\n" 
        << std::endl;
}

int main() {
    test_title(VIOLET900"TEST ABSTRACT");

    std::cout 
        << " You see this message only beacuase " 
        << BOLD VIOLET600 "pabecka " RESET
        << "cannot be " BOLD PINK300 "Animal" RESET << std::endl
        << PURPLE500" 😲 Crazyyy, right?" << std::endl
        << std::endl;

    // Animal pabecka();
    // (void)pabeckha;
    return 0;
}
