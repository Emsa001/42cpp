/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:51 by escura            #+#    #+#             */
/*   Updated: 2024/08/04 19:26:49 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and destructors

Fixed::Fixed() : _value(0)
{
    if(DEBUG)
        std::cout << GREEN"Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    if(DEBUG)
        std::cout << CYAN"Copy constructor called" << RESET  << std::endl;
    *this = src;
}

Fixed::Fixed(const int integer)
{
    if(DEBUG)
        std::cout << BLUE"Int constructor called" << RESET  << std::endl;
    _value = integer << _fractionalBits;
}

Fixed::Fixed(const float floating)
{
    if(DEBUG)
        std::cout << MAGENTA"Float constructor called" << RESET  << std::endl;
    _value = roundf(floating * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    if(DEBUG)
        std::cout << RED"Destructor called" << RESET  << std::endl;
}

// Operator overloads

Fixed &Fixed::operator=(const Fixed &src)
{
    if(DEBUG)
        std::cout << YELLOW"Copy assignation operator called" << RESET  << std::endl;
    _value = src.getRawBits();
    return (*this);
}

// >, <, >=, <=, == and !=

bool Fixed::operator>(const Fixed &src) const
{
    return (this->_value > src._value);
}

bool Fixed::operator<(const Fixed &src) const
{
    return (this->_value < src._value);
}

bool Fixed::operator>=(const Fixed &src) const
{
    return (this->_value >= src._value);
}

bool Fixed::operator<=(const Fixed &src) const
{
    return (this->_value <= src._value);
}

bool Fixed::operator==(const Fixed &src) const
{
    return (this->_value == src._value);
}

bool Fixed::operator!=(const Fixed &src) const
{
    return (this->_value != src._value);
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &src) const
{
    return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const 
{
    return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed Fixed::operator++(int)
{
    Fixed answer(*this);
    ++_value;
    return (answer);
}

Fixed Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed answer(*this);
    --_value;
    return (answer);
}

Fixed Fixed::operator--()
{
    _value--;
    return (*this);
}

// Member functions

int Fixed::getRawBits( void ) const
{
    if(DEBUG)
        std::cout << BLUE"getRawBits member function called" << RESET  << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    if(DEBUG)
        std::cout << MAGENTA"setRawBits member function called" << RESET  << std::endl;
    _value = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (_value >> _fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if(a._value < b._value)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if(a._value > b._value)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if(a._value < b._value)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if(a._value > b._value)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &src){
    out << src.toFloat();
    return (out);
}