/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:56 by escura            #+#    #+#             */
/*   Updated: 2024/07/04 16:54:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int c, char **v){
    if(c == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);

    while(*(++v)){
        while(**v) std::cout << (char)toupper(*((*v)++));
        *(v + 1) && std::cout << " ";
    }
    
    return (std::cout << "\n", 0);
}
