/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:51 by escura            #+#    #+#             */
/*   Updated: 2024/08/04 18:09:49 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << GREEN"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << CYAN"Copy constructor called" << RESET  << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << YELLOW"Copy assignation operator called" << RESET  << std::endl;
    _value = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << RED"Destructor called" << RESET  << std::endl;
}

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