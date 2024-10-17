/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:28:19 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 19:09:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

static void nl(int times = 0){
    for (int i = 0; i <= times; i++)
        std::cout << std::endl;
}

static void test_title(std::string title){
    nl();
    std::cout 
        << "\n" BG_STONE200 GRAY900"[ " BOLD << title << RESET BG_STONE200 GRAY900" ]" RESET "\n" 
        << std::endl;
    nl();
}

void test_ptr(){
    test_title(" Test Pointer ");

    Base* r1 = generate();
    Base* r2 = generate(); 
    Base* r3 = generate(); 

    nl();

    identify(r1);
    identify(r2);
    identify(r3);

    nl();
    delete r1;
    delete r2;
    delete r3;
}

void test_ref(){
    test_title("Test Reference");

    Base* r1 = generate();
    Base* r2 = generate(); 
    Base* r3 = generate(); 

    nl();

    identify(*r1);
    identify(*r2);
    identify(*r3);

    nl();
    delete r1;
    delete r2;
    delete r3;
}


void test_ellen(){

    test_title("  Test Ellen  ");

    Base *newGeneratedClass;

    newGeneratedClass = generate();
    identify(newGeneratedClass);
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    newGeneratedClass = generate();
    identify(&(*newGeneratedClass));
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    newGeneratedClass = generate();
    identify(newGeneratedClass);
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    std::cout << BG_GRAY800 GRAY300 " Respectfully borrowed from Ellen 🙏 " << std::endl;
}

int main(){

    srand (time(NULL));

    test_ptr();
    test_ref();
    test_ellen();
    
    nl();
    return (0);
}