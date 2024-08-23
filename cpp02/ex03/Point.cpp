/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:08:07 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 14:44:31 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and destructors

Point::Point(): _x(0), _y(0){
    if(DEBUG)
        std::cout << GREEN"Point Default Constructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y){
    if(DEBUG)
        std::cout << GREEN"Point Constructor called" << std::endl;
}

Point::Point(const Point &point): _x(point._x), _y(point._y){
    if(DEBUG)
        std::cout << GREEN"Point Copy Constructor called" << std::endl;
}

Point::~Point(){
    if(DEBUG)
        std::cout << GREEN"Point Deconstructor called" << std::endl;  
}

// Member functions

Fixed Point::getX() const{
    return (_x);
}

Fixed Point::getY() const{
    return (_y);
}