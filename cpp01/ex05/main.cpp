/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:07:05 by escura            #+#    #+#             */
/*   Updated: 2024/08/02 22:15:29 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void){
    Harl harl;

    std::cout << std::endl;

    harl.complain("debug");
    harl.complain("warning");
    std::cout << std::endl << std::endl;

    // flag
    harl.complain("info");
    harl.complain("info");
    harl.complain("info");

    harl.complain("salami");
    harl.complain("pizza");
    harl.complain("pasta");

    harl.complain("error");
    harl.complain("error");
    harl.complain("error");

    std::cout << std::endl;

    return 0;
}
