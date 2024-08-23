/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:07:17 by escura            #+#    #+#             */
/*   Updated: 2024/08/02 22:15:40 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <ctype.h>

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr 
            << RED"Mamma mia 🤌🤌" << RESET 
            <<"\nThis is how you should use it: "
            << PURPLE << argv[0] << " <level>" << RESET
            << std::endl;
        return 1;
    }

    for(int i = 0; argv[1][i]; i++)
        argv[1][i] = std::tolower(argv[1][i]);

    Harl harl;
    std::cout << std::endl;
    harl.complain(argv[1]);
    std::cout << std::endl;

    return 0;
}
