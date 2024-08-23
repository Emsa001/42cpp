/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:49 by escura            #+#    #+#             */
/*   Updated: 2024/08/05 15:49:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define DEBUG false

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &src);            // Copy constructor
        Fixed(const int integer);
        Fixed(const float floating);
        
        // Assignment operator overload
        Fixed &operator=(const Fixed &src);

        // Comparing operators
        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;

        // Arithmetic operators
        Fixed operator+(const Fixed &src) const;
        Fixed operator-(const Fixed &src) const;
        Fixed operator*(const Fixed &src) const;
        Fixed operator/(const Fixed &src) const;

        // pre/post increment and decrement operators
        Fixed operator++();         // pre-increment
        Fixed operator++(int);      // post-increment
        Fixed operator--();         // pre-decrement
        Fixed operator--(int);      // post-decrement
        
        ~Fixed();

        // Member functions

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif