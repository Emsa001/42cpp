/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:43:16 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 15:56:00 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void check(bool expected, bool result)
{
    if (expected == result)
        std::cout << GREEN << "OK" << RESET << std::endl;
    else
        std::cout << RED << "KO" << RESET << std::endl;
}

void test_inside()
{
    std::cout << BLUE"\n\n===[ Test Inside ]===\n\n" << RESET << std::endl;

    // triangle
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);

    Point points[] = {
        Point(0, 0),
        Point(10, 30),
        Point(20, 0),
        Point(10, 10),
        Point(7, 3),
        Point(20, 0),
        Point(0, 0),
        Point(10, 30),
        Point(19.999, 0),
        Point(10, 3.34)};

    for (int i = 0; i < 10; i++)
    {
        bool result = bsp(a, b, c, points[i]);

        Fixed x = points[i].getX();
        Fixed y = points[i].getY();

        std::cout 
            << "Is point [ " << CYAN << x << RESET", " << YELLOW << y << RESET" ]"
            << " inside triangle? : (" << result << ") ";
        check(true, result);
    }
}

void test_outside()
{
    std::cout << BLUE"\n\n===[ Test Outside ]===\n\n" << RESET << std::endl;

    // triangle
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);

    Point points[] = {
        Point(0, 1),
        Point(10, 31),
        Point(20, 1),
        Point(10, 31),
        Point(0.7, 20.1),
        Point(20, 1),
        Point(0, 1),
        Point(10, 31),
        Point(20.1, 1),
        Point(10, 84.35)};

    for (int i = 0; i < 10; i++)
    {
        bool result = bsp(a, b, c, points[i]);

        Fixed x = points[i].getX();
        Fixed y = points[i].getY();

        std::cout 
            << "Is point [ " << CYAN << x << RESET", " << YELLOW << y << RESET" ]"
            << " inside triangle? : (" << result << ") ";
            
        check(false, result);
    }

}

int main(void)
{
    test_inside();
    test_outside();
    return 0;
}