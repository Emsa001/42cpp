/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:30:51 by escura            #+#    #+#             */
/*   Updated: 2024/10/14 20:47:32 by escura           ###   ########.fr       */
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

int ScalarConverter::convertToInt(const std::string &str){
    long int value;
    char* endptr;

    value = std::strtol(str.c_str(), &endptr, 10);
    if (endptr == str.c_str()) {
        throw std::runtime_error("Impossible");
    } else if (errno == ERANGE) {
        throw std::runtime_error("+inff");
    }
    
    return value;
}

char ScalarConverter::convertToChar(const std::string &str){
    char c;
    if(str.length() == 1){
        c = str[0];
    } else {
        int typeInt = convertToInt(str);
        c = static_cast<char>(typeInt);
    }

    if(!std::isprint(c))
        throw std::runtime_error("Non displayable");

    return c;
}

float ScalarConverter::convertToFloat(const std::string &str){
    float value;
    char* endptr;

    value = std::strtof(str.c_str(), &endptr);
    if (endptr == str.c_str()) {
        throw std::runtime_error("Impossible");
    } else if (errno == ERANGE) {
        throw std::runtime_error("+inff");
    }

    return value;
}

double ScalarConverter::convertToDouble(const std::string &str){
    double value;
    char* endptr;

    value = std::strtod(str.c_str(), &endptr);
    if (endptr == str.c_str()) {
        throw std::runtime_error("Impossible");
    } else if (errno == ERANGE) {
        throw std::runtime_error("+inff");
    }

    return value;
}

template<typename Func>
std::string tryConvert(const std::string &str, Func convertFunc, std::string type) {
    std::stringstream temp;
    try {
        temp << convertFunc(str);
        std::string result = temp.str();

        if(type == "float" || type == "double"){
            if(result.find('.') == std::string::npos)
                result += ".0";
            if(type == "float")
                result += "f";
        }
        return result;
    } catch (const std::exception &e) {
        return e.what();
    }
}

void ScalarConverter::convert(const std::string &str){
    std::string typeChar = tryConvert(str, &convertToChar, "char");
    std::string typeInt = tryConvert(str, &convertToInt, "int");
    std::string typeFloat = tryConvert(str, &convertToFloat, "float");
    std::string typeDouble = tryConvert(str, &convertToDouble, "double");

    std::cout 
        << "char: " << typeChar << "\n"
        << "int: " << typeInt << "\n"
        << "float: " << typeFloat << "\n"
        << "double: " << typeDouble << "\n"
        <<std::endl;
}