/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:27:27 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 16:52:24 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Colors.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cerrno>
#include <limits.h>
#include <limits>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);

    public:
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
        
        static void convert(const std::string &str);
        static char convertToChar(const std::string &str);
        static long int convertToInt(const std::string &str);
        static float convertToFloat(const std::string &str);
        static double convertToDouble(const std::string &str);

        static std::string tryConvert(const std::string &str, char type);
        static std::string specialCases(const std::string &str, char type);
        static std::string formatOutput(std::stringstream &temp, char type);
        static char getInputType(const std::string &str);

};

bool is_num(const std::string& str);

#endif