/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:30:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 16:56:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " ScalarConverter" RESET " "
        << "Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    std::cout
        << BG_GREEN600 "[ CONSTRUCTOR ]" RESET
        << LIME400 " ScalarConverter" RESET " "
        << "Copy Constructor called" << std::endl;

    ScalarConverter::operator=(src);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this == &src)
        return *this;

    std::cout
        << BG_GREEN500 "[  OPERATOR   ]" RESET
        << LIME400 " ScalarConverter" RESET " "
        << "Copy Assignment operator called" << std::endl;

    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " ScalarConverter" RESET " "
        << "Destructor called" << std::endl;
}

// public members

long int ScalarConverter::convertToInt(const std::string &str)
{
    char *endptr;
    long int value = std::strtol(str.c_str(), &endptr, 10);

    if (*endptr != '\0' || value > INT_MAX || value < INT_MIN)
        throw std::runtime_error("Impossible");
    return value;
}

float ScalarConverter::convertToFloat(const std::string &str)
{
    char *endptr;
    float value = std::strtof(str.substr(0, str.length() - 1).c_str(), &endptr);

    if (*endptr != '\0' || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max() || str[str.length() - 1] != 'f'){
        throw std::runtime_error("Impossible");
    }

    return value;
}

double ScalarConverter::convertToDouble(const std::string &str)
{
    char *endptr;
    double value = std::strtod(str.c_str(), &endptr);

    if (*endptr != '\0' || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max() || !is_num(str))
        throw std::runtime_error("Impossible");
    return value;
}

std::string ScalarConverter::tryConvert(const std::string &str, char type) {
    std::stringstream temp;
    
    char charType;
    long int intType;
    float floatType;
    double doubleType;

    try {
        const std::string specialCase = specialCases(str, type);
        if (!specialCase.empty())
            return specialCase;

        char inputType = getInputType(str);

        switch (inputType) {
            case 'c':
                charType = str[0];
                switch (type) {
                    case 'f': floatType = static_cast<float>(charType); break;
                    case 'd': doubleType = static_cast<double>(charType); break;
                    case 'i': intType = static_cast<long int>(charType); break;
                }
                break;

            case 'i':
                intType = convertToInt(str);
                switch (type) {
                    case 'f': floatType = static_cast<float>(intType); break;
                    case 'd': doubleType = static_cast<double>(intType); break;
                    case 'c':
                        if (intType < CHAR_MIN || intType > CHAR_MAX)
                            throw std::runtime_error("Impossible");
                        charType = static_cast<char>(intType);
                        break;
                }
                break;

            case 'f':
                floatType = convertToFloat(str);
                switch (type) {
                    case 'd': doubleType = static_cast<double>(floatType); break;
                    case 'i': 
                        if (floatType > INT_MAX || floatType < INT_MIN)
                            throw std::runtime_error("Impossible");
                        intType = static_cast<long int>(floatType); 
                        break;
                    case 'c':
                        if (floatType < CHAR_MIN || floatType > CHAR_MAX)
                            throw std::runtime_error("Impossible");
                        charType = static_cast<char>(floatType); 
                        break;
                }
                break;

            case 'd':
                doubleType = convertToDouble(str);
                switch (type) {
                    case 'f':
                        if (doubleType > std::numeric_limits<float>::max() || doubleType < -std::numeric_limits<float>::max())
                            throw std::runtime_error("Impossible");
                        floatType = static_cast<float>(doubleType);
                        break;
                    case 'i':
                        if (doubleType > INT_MAX || doubleType < INT_MIN)
                            throw std::runtime_error("Impossible");
                        intType = static_cast<long int>(doubleType); 
                        break;
                    case 'c':
                        if (doubleType < CHAR_MIN || doubleType > CHAR_MAX)
                            throw std::runtime_error("Impossible");
                        charType = static_cast<char>(doubleType);
                        break;
                }
                break;

            default:
                throw std::runtime_error("Impossible");
        }

        switch (type) {
            case 'c': temp << charType; break;
            case 'i': temp << intType; break;
            case 'f': temp << floatType; break;
            case 'd': temp << doubleType; break;
            default: throw std::runtime_error("Impossible");
        }
        
            
        return formatOutput(temp, type);

    } catch (const std::exception &e) {
        return e.what();
    }
}

void ScalarConverter::convert(const std::string &str)
{
    std::string typeChar = tryConvert(str, 'c');
    std::string typeInt = tryConvert(str, 'i');
    std::string typeFloat = tryConvert(str, 'f');
    std::string typeDouble = tryConvert(str, 'd');

    std::cout
        << BOLD BG_PINK500 "char  :" << RESET " " PINK400 << typeChar << "\n"
        << RESET
        << BOLD BG_PURPLE500 "int   :" << RESET " " PURPLE400 << typeInt << "\n"
        << RESET
        << BOLD BG_VIOLET500 "float :" << RESET " " VIOLET400 << typeFloat << "\n"
        << RESET
        << BOLD BG_INDIGO500 "double:" << RESET " " INDIGO400 << typeDouble << RESET
        << std::endl;
}