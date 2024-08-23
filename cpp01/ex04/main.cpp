/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:06:38 by escura            #+#    #+#             */
/*   Updated: 2024/08/01 21:49:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv){
    
    if(argc != 4)
    {
        std::cerr 
            << RED"Mamma mia 🤌🤌" << RESET 
            <<"\nThis is how you should use it: "
            << PURPLE << argv[0] << " <filename> <old_word> <new_word>" << RESET
            << std::endl;
        return 1;
    }
    

    std::string filename = argv[1];
    std::string old_word = argv[2];
    std::string new_word = argv[3];

    Replacer replacer(filename, old_word, new_word);
    replacer.run();

    return 0;
}
