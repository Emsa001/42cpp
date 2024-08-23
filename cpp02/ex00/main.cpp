/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:43:16 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 15:48:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test_subject(){
    std::cout << BLUE"\n\n===[ Test subject ]===\n\n" << RESET << std::endl;

    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}

void test_1()
{
    std::cout << BLUE"\n\n===[ Test 1 ]===\n\n" << RESET << std::endl;
    
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    a.setRawBits(123);
    b.setRawBits(-2147483648);
    c.setRawBits(2147483647);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return;
}

int main(void)
{
    test_subject();
    // test_1();
    return 0;
}