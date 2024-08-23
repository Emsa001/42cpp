/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:05:59 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:28:22 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define AQUA "\033[1;36m"
#define RESET "\033[0m"

int main(void){
    std::string myString = "HI THIS IS BRAIN";

    void *stringPTR = &myString;
    std::string &stringREF = myString;

    std::cout << "🤯 Memory address of the string: " << AQUA << &myString << RESET << std::endl;
    std::cout << "🤯🤯 Memory address of the string pointer:  " << AQUA << stringPTR << RESET << std::endl;
    std::cout << "🤯🤯🤯 Memory address of the string reference: " << AQUA << &stringREF << RESET << std::endl; 


    std::cout << "😱 Value of the string: " << AQUA << myString << RESET <<std::endl;
    std::cout << "😱😱 Value of the string pointer:  " << AQUA << *(std::string *)stringPTR << RESET << std::endl;
    std::cout << "😱😱😱 Value of the string reference: " << AQUA << stringREF << RESET << std::endl; 
}
