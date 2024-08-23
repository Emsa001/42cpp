/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:43:16 by escura            #+#    #+#             */
/*   Updated: 2024/08/07 14:31:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test_subject(){
    std::cout << BLUE"\n\n===[ Test subject ]===\n\n" << RESET << std::endl;

    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void test_1(){
    std::cout << BLUE"\n\n===[ Test 1 ]===\n\n" << RESET << std::endl;

    Fixed a;

    std::cout << a << std::endl;
    a = 10.8000001f;
    std::cout << a << std::endl;
    a = Fixed(11.8000001f);
    std::cout << a << std::endl;
}

void test_2(){
    std::cout << BLUE"\n\n===[ Test 2 ]===\n\n" << std::endl;

    Fixed const b(10);
    Fixed c(42.42f);
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    c = b;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

void test_3(){
    std::cout << BLUE"\n\n===[ Test 3 ]===\n\n" << std::endl;

    Fixed a = Fixed(50.5f);
    Fixed b = Fixed(a);
    Fixed c = Fixed(b);
    Fixed d = Fixed(c);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
}

void test_5(){
    std::cout << BLUE"\n\n===[ Test 5 ]===\n\n" << std::endl;

    Fixed a;

    std::cout << a << std::endl;
}

int main(void)
{
    test_subject();
    test_1();
    test_2();
    test_3();
    test_5();
    return 0;
}