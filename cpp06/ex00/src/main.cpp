/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:30:59 by escura            #+#    #+#             */
/*   Updated: 2024/10/15 19:14:26 by escura           ###   ########.fr       */
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

static void test_multiple(){
    std::string test[] = {
        "0",
        "0.0",
        "42",
        "42.0",
        "42.42f",
        "-4.2",
        "4.2",
        "-inff",
        "+inff",
        "nanf",
        "-inf",
        "+inf",
        "nan",
        ""
    };

    for (int i = 0; !test[i].empty(); i++)
    {
        test_title("Converting " + test[i]);
        ScalarConverter::convert(test[i]);
    }
}

int main(int argc, char **argv)
{
    test_multiple();

    if (argc != 2)
    {
        std::cout
            << BG_RED800 "[  ARG ERROR  ]" RESET
            << RED400 " Correct Usage:" RESET " "
            << argv[0] << " <arg>" << std::endl;
        return (1);
    }

    test_title("Converting " + std::string(argv[1]));
    ScalarConverter::convert(argv[1]);

    nl();
    return (0);
}