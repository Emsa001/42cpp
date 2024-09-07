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
        Bureaucrat *Tobby = new Bureaucrat("Tobby", 50);
        Form *DbTicket = new Form("DB Ticket", 50, 50);

        nl();

        std::cout << Tobby << std::endl;
        std::cout << DbTicket << std::endl;

        nl();

        Tobby->signForm(*DbTicket);
        Tobby->signForm(*DbTicket);

        nl();
        
        Form *ICETicket = new Form("ICE Ticket", 150, 150);
        Tobby->signForm(*ICETicket);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
