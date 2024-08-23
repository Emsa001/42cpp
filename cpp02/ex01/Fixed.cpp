/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:51 by escura            #+#    #+#             */
/*   Updated: 2024/08/07 14:32:05 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and destructors

Fixed::Fixed() : _value(0)
{
    std::cout << GREEN"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << CYAN"Copy constructor called" << RESET  << std::endl;
    *this = src;
}

Fixed::Fixed(const int integer)
{
    std::cout << BLUE"Int constructor called" << RESET  << std::endl;
    _value = integer << _fractionalBits;
}

Fixed::Fixed(const float floating)
{
    std::cout << MAGENTA"Float constructor called" << RESET  << std::endl;
    _value = roundf(floating * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << RED"Destructor called" << RESET  << std::endl;
}

// Operator overloads

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << YELLOW"Copy assignation operator called" << RESET  << std::endl;
    _value = src.getRawBits();
    return (*this);
}

// Member functions

int Fixed::getRawBits( void ) const
{
    std::cout << BLUE"getRawBits member function called" << RESET  << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << MAGENTA"setRawBits member function called" << RESET  << std::endl;
    _value = raw;
}


float Fixed::toFloat( void ) const
{
    // std::cout << "INT: " <<  _value << std::endl;
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src){
    out << src.toFloat();
    return (out);
}