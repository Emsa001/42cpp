/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:49 by escura            #+#    #+#             */
/*   Updated: 2024/08/07 14:30:50 by escura           ###   ########.fr       */
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
        
        Fixed &operator=(const Fixed &src); // Assignment operator overload
        
        ~Fixed();

        // Member functions

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif