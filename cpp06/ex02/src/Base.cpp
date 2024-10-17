/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:15:31 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 19:05:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base()
{
    std::cout
        << BG_RED600 "[  DESTRUCTOR  ]" RESET
        << RED400 " Base" RESET " "
        << "Destructor called" << std::endl;
}

Base* generate(void)
{
    Base* obj = NULL;

    switch(rand() % 3 + 1){
        case 1: 
            obj = new A;
            std::cout 
                << BG_PINK500 " " << obj << " " 
                << RESET " new " PINK400 "A" RESET " created" 
                << std::endl;
            break;
        case 2:
            obj = new B;
            std::cout 
                << BG_PURPLE500 " " << obj << " " 
                << RESET " new " PURPLE400 "B" RESET " created" 
                << std::endl;
            break;
        case 3:
            obj = new C;
            std::cout 
                << BG_INDIGO400 " " << obj << " " 
                << RESET " new " INDIGO400 "C" RESET " created" 
                << std::endl;            break;
    }

    return obj;
}

void identify(Base* p){
    if(p == dynamic_cast<A*>(p)){
        std::cout 
            << BG_PINK500 " " << p << " "
            << RESET " is type " PINK400 "A" 
            << RESET << std::endl;
    }
    else if(p == dynamic_cast<B*>(p)){
        std::cout 
            << BG_PURPLE500 " " << p << " " 
            << RESET " is type " PURPLE400 "B" 
            << RESET << std::endl;
    }
    else if(p == dynamic_cast<C*>(p)){
        std::cout 
            << BG_INDIGO400 " " << p << " "
            << RESET " is type " INDIGO400 "C" 
            << RESET << std::endl;
    }
}

void identify(Base& p){
    if(&p == dynamic_cast<A*>(&p)){
        std::cout 
            << BG_PINK500 " " << &p << " "
            << RESET " is type " PINK400 "A" 
            << RESET << std::endl;
    }
    else if(&p == dynamic_cast<B*>(&p)){
        std::cout 
            << BG_PURPLE500 " " << &p << " " 
            << RESET " is type " PURPLE400 "B" 
            << RESET << std::endl;
    }
    else if(&p == dynamic_cast<C*>(&p)){
        std::cout 
            << BG_INDIGO400 " " << &p << " "
            << RESET " is type " INDIGO400 "C" 
            << RESET << std::endl;
    }
}