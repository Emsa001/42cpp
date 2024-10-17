/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:12:03 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 19:10:04 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

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

void test_1(){
    test_title("Test 1");

    Data data;

    data.s1 = "Hello";
    data.s2 = "World";
    data.n = 42;

    std::cout 
        << BG_PURPLE900 " Data  :" RESET " " 
        << BLUE300 << &data 
        << RESET << std::endl;

    std::cout 
        << BG_PURPLE800 "Data.s1:" RESET " " 
        << BLUE400 << data.s1 
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.s2:" RESET " " 
        << BLUE400 << data.s2
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.n :" RESET " " 
        << BLUE400 << data.n
        << RESET << std::endl;

    nl();

    uintptr_t raw = Serializer::serialize(&data);
    std::cout 
        << BG_PINK800 "  Raw  :" RESET " " 
        << BLUE300 << raw 
        << RESET << std::endl;

    nl();

    Data *ptr = Serializer::deserialize(raw);
    std::cout 
        << BG_INDIGO800 "  ptr  :" RESET " " 
        << BLUE300 << ptr 
        << RESET << std::endl;

    std::cout 
        << BG_INDIGO600 "ptr->s1:" RESET " " 
        << BLUE400 << ptr->s1 
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->s2:" RESET " " 
        << BLUE400 << ptr->s2
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->n :" RESET " " 
        << BLUE400 << ptr->n
        << RESET << std::endl;
}

void test_2(){
    test_title("Test 2");

    Data* data = new Data;
    data->s1 = "World";
    data->s2 = "Hello";
    data->n = 24;

    std::cout 
        << BG_PURPLE900 " Data  :" RESET " " 
        << BLUE300 << data 
        << RESET << std::endl;

    std::cout 
        << BG_PURPLE800 "Data.s1:" RESET " " 
        << BLUE400 << data->s1 
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.s2:" RESET " " 
        << BLUE400 << data->s2
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.n :" RESET " " 
        << BLUE400 << data->n
        << RESET << std::endl;

    nl();

    uintptr_t raw = Serializer::serialize(data);
    std::cout 
        << BG_PINK800 "  Raw  :" RESET " " 
        << BLUE300 << raw 
        << RESET << std::endl;

    nl();

    Data *ptr = Serializer::deserialize(raw);
    std::cout 
        << BG_INDIGO800 "  ptr  :" RESET " " 
        << BLUE300 << ptr 
        << RESET << std::endl;

    std::cout 
        << BG_INDIGO600 "ptr->s1:" RESET " " 
        << BLUE400 << ptr->s1 
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->s2:" RESET " " 
        << BLUE400 << ptr->s2
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->n :" RESET " " 
        << BLUE400 << ptr->n
        << RESET << std::endl;

    delete data;
}

void test_3(){
    test_title("Test 3");

    Data data;

    std::cout 
        << BG_PURPLE900 " Data  :" RESET " " 
        << BLUE300 << &data 
        << RESET << std::endl;

    std::cout 
        << BG_PURPLE800 "Data.s1:" RESET " " 
        << BLUE400 << data.s1 
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.s2:" RESET " " 
        << BLUE400 << data.s2
        << RESET << std::endl;
    std::cout 
        << BG_PURPLE800 "Data.n :" RESET " " 
        << BLUE400 << data.n
        << RESET << std::endl;

    nl();

    uintptr_t raw = Serializer::serialize(&data);
    std::cout 
        << BG_PINK800 "  Raw  :" RESET " " 
        << BLUE300 << raw 
        << RESET << std::endl;

    nl();

    Data *ptr = Serializer::deserialize(raw);
    std::cout 
        << BG_INDIGO800 "  ptr  :" RESET " " 
        << BLUE300 << ptr 
        << RESET << std::endl;

    std::cout 
        << BG_INDIGO600 "ptr->s1:" RESET " " 
        << BLUE400 << ptr->s1 
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->s2:" RESET " " 
        << BLUE400 << ptr->s2
        << RESET << std::endl;
    std::cout 
        << BG_INDIGO600 "ptr->n :" RESET " " 
        << BLUE400 << ptr->n
        << RESET << std::endl;
}

int main(){

    test_1();
    test_2();
    test_3();

    nl();
    return (0);
}