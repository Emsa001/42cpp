/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:30:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/14 21:44:03 by escura           ###   ########.fr       */
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

ScalarConverter::~ScalarConverter()
{
    std::cout
        << BG_RED600 "[ DESTRUCTOR  ]" RESET
        << RED400 " ScalarConverter" RESET " "
        << "Destructor called" << std::endl;
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

template<typename T>
T convertTo(const std::string &str, T (*convertFunc)(const char*, char**, int)) {
    T value;
    char* endptr;
    errno = 0;

    value = convertFunc(str.c_str(), &endptr, 10);
    if (endptr == str.c_str() || errno == ERANGE) {
        throw std::runtime_error("Impossible");
    }
    return value;
}

template<typename T>
T convertTo(const std::string &str, T (*convertFunc)(const char*, char**)) {
    T value;
    char* endptr;
    errno = 0;

    value = convertFunc(str.c_str(), &endptr);
    if (endptr == str.c_str() || errno == ERANGE) {
        throw std::runtime_error("Impossible");
    }
    return value;
}

int ScalarConverter::convertToInt(const std::string &str) {
    long int value = convertTo<long int>(str, std::strtol);
    if(value > INT_MAX || value < INT_MIN)
        throw std::runtime_error("Impossible");
    return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(const std::string &str) {
    return convertTo<float>(str, std::strtof);
}

double ScalarConverter::convertToDouble(const std::string &str) {
    return convertTo<double>(str, std::strtod);
}

char ScalarConverter::convertToChar(const std::string &str) {
    if (str.length() == 1 && isprint(str[0])) {
        return str[0];
    } else {
        int intValue = convertToInt(str);
        char c = static_cast<char>(intValue);
        if (!isprint(c)) {
            throw std::runtime_error("Non displayable");
        }
        return c;
    }
}

template<typename Func>
std::string tryConvert(const std::string &str, Func convertFunc, const std::string &suffix = "") {
    std::stringstream temp;
    try {
        temp << convertFunc(str);
        std::string result = temp.str();
        if (!suffix.empty() && result.find('.') == std::string::npos)
            result += ".0";
        return result + (suffix != " " ? suffix : "");
    } catch (const std::exception &e) {
        return e.what();
    }
}

void ScalarConverter::convert(const std::string &str){
    std::string typeChar = tryConvert(str, &convertToChar);
    std::string typeInt = tryConvert(str, &convertToInt);
    std::string typeFloat = tryConvert(str, &convertToFloat, "f");
    std::string typeDouble = tryConvert(str, &convertToDouble, " ");

    if(str == "inf" || str == "inf" || str == "nan")
    {
        typeFloat = str + "f";
        typeDouble = str;
    }
    if(str == "inff" || str == "inff" || str == "nanf")
    {
        typeFloat = str;
        typeDouble = str.substr(0, str.length() - 1);
    }

    std::cout 
        << BOLD  BG_PINK500   "char  :" << RESET " " PINK400 << typeChar << "\n" << RESET
        << BOLD  BG_PURPLE500 "int   :" << RESET " " PURPLE400 <<  typeInt << "\n" << RESET
        << BOLD  BG_VIOLET500 "float :" << RESET " " VIOLET400 <<  typeFloat << "\n" << RESET
        << BOLD  BG_INDIGO500 "double:" << RESET " " INDIGO400 << typeDouble << RESET
        << std::endl;
}