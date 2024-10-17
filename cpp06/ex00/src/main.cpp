/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:30:59 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 19:10:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}

static void test_title(std::string title){
    std::cout 
        << "\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n" 
        << std::endl;
}


int main(int argc, char **argv)
{
    // ScalarConverter *convert = new ScalarConverter(); 
    // ScalarConverter convert2;

    if (argc != 2)
    {
        nl();
        std::cerr
            << BG_RED800 "[  ARG ERROR  ]" RESET
            << RED400 " Correct Usage:" RESET " "
            << argv[0] << " <arg>" << std::endl;
        nl();
        return (1);
    }


    std::string typeStr;
    switch(ScalarConverter::getInputType(argv[1])){
        case 'i':
            typeStr = "int";
            break;
        case 'f':
            typeStr = "float";
            break;
        case 'd':
            typeStr = "double";
            break;
        case 'c':
            typeStr = "char";
            break;
        default:
            typeStr = "unknown";
            break;
    }

    test_title("Converting " PURPLE800 + std::string(argv[1]) + BG_STONE200 GRAY900 " as: " + PURPLE800 + typeStr);
    ScalarConverter::convert(argv[1]);

    nl();
    return (0);
}