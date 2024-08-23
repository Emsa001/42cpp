/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:43:16 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 15:54:11 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test_subject()
{
    std::cout << BLUE"\n\n===[ Test subject ]===\n\n" << RESET << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
}

void test_1() {
    std::cout << BLUE"\n\n===[ Test 1 ]===\n\n" << RESET << std::endl;

    Fixed a(10.0f);
    Fixed b(10.0f);
    Fixed c = a + b;

    std::cout << YELLOW "A: " << GREEN << a << RESET << std::endl;
    std::cout << YELLOW "B: " << GREEN << b << RESET << std::endl;
    std::cout << YELLOW "C: " << GREEN << c << RESET << std::endl;

    Fixed d(0);
    Fixed e(0);
    d++;
    d++;
    d++;
    d--;
    d--;

    std::cout << YELLOW "++D: " << GREEN << ++d << RESET << std::endl;
    std::cout << YELLOW "D: " << GREEN << d << RESET << std::endl;

    std::cout << YELLOW "++E: " << GREEN << e++ << RESET << std::endl;
    std::cout << YELLOW "E: " << GREEN << e << RESET << std::endl;
}

void test_2() {
    std::cout << BLUE"\n\n===[ Test 2 ]===\n\n" << RESET << std::endl;

    Fixed x1(10.0f);
    Fixed y1(10.0f);

    Fixed x2(3.0f);
    Fixed y2(3.1f);

    Fixed x3(17.0f);
    Fixed y4(0);

    std::cout << YELLOW "max(x1, y1): " << GREEN << Fixed::max(x1, y1) << RESET << std::endl;
    std::cout << YELLOW "max(x2, y2): " << GREEN << Fixed::max(x2, y2) << RESET << std::endl;
    std::cout << YELLOW "max(x3, y4): " << GREEN << Fixed::max(x3, y4) << RESET << std::endl;

    std::cout << YELLOW "min(x1, y1): " << GREEN << Fixed::min(x1, y1) << RESET << std::endl;
    std::cout << YELLOW "min(x2, y2): " << GREEN << Fixed::min(x2, y2) << RESET << std::endl;
    std::cout << YELLOW "min(x3, y4): " << GREEN << Fixed::min(x3, y4) << RESET << std::endl;
}

void test_3() {
    std::cout << BLUE"\n\n===[ Test 3 ]===\n\n" << RESET << std::endl;

    Fixed a(10.0f);

    std::cout << YELLOW "a + 10: " << GREEN << a + 10 << RESET << std::endl;
    std::cout << YELLOW "a - 10: " << GREEN << a - 10 << RESET << std::endl;
    std::cout << YELLOW "a * 10: " << GREEN << a * 10 << RESET << std::endl;
    std::cout << YELLOW "a / 10: " << GREEN << a / 0 << RESET << std::endl;
}

void test_4(){
    std::cout << BLUE"\n\n===[ Test 3 ]===\n\n" << RESET << std::endl;

    Fixed a(10.0f);
    Fixed b(10.0f);

    std::cout << YELLOW << "a (" << a << ") " << CYAN << "< " << YELLOW << " b (" << b << "): " << GREEN << (a < b) << RESET << std::endl;
    std::cout << YELLOW << "a (" << a << ") " << CYAN << "> " << YELLOW << " b (" << b << "): " << GREEN << (a > b) << RESET << std::endl;
    std::cout << YELLOW << "a (" << a << ") " << CYAN << "<=" << YELLOW << " b (" << b << "): " << GREEN << (a <= b) << RESET << std::endl;
    std::cout << YELLOW << "a (" << a << ") " << CYAN << ">=" << YELLOW << " b (" << b << "): " << GREEN << (a >= b) << RESET << std::endl;
    std::cout << YELLOW << "a (" << a << ") " << CYAN << "==" << YELLOW << " b (" << b << "): " << GREEN << (a == b) << RESET << std::endl << std::endl;
}

int main(void)
{
    test_subject();
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}