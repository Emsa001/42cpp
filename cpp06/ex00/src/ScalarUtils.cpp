/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:27:23 by escura            #+#    #+#             */
/*   Updated: 2024/10/17 16:55:54 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

bool is_num(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++){
        if(std::isdigit(str[i]) == 0 && str[i] != '.' && str[i] != 'f')
            return false;
    }

    return true;
}

std::string ScalarConverter::specialCases(const std::string &str, char type)
{
    std::stringstream temp;

    if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
    {
        switch (type)
        {
            case 'f':
                temp << str;
                return temp.str();
            case 'd':
                temp << str.substr(0, str.length() - 1);
                return temp.str();
            case 'i':
            case 'c':
                throw std::runtime_error("impossible");
        }
        return temp.str();
    }
    else if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
    {
        switch (type)
        {
            case 'f':
                temp << str << "f";
                return temp.str();
            case 'd':
                temp << str;
                return temp.str();
            case 'i':
            case 'c':
                throw std::runtime_error("impossible");
        }
        return temp.str();
    }

    return "";
}

std::string ScalarConverter::formatOutput(std::stringstream &temp, char type)
{
    switch (type)
    {
        case 'f':
        case 'd':
            if (temp.str().find('.') == std::string::npos)
                temp << ".0";
            if (type == 'f')
                temp << "f";
            break;
        case 'c':
            if (!isprint(static_cast<char>(temp.str()[0])))
                throw std::runtime_error("Non displayable");
            return "'" + temp.str() + "'";
            break;
    }

    return temp.str();
}

char ScalarConverter::getInputType(const std::string &str)
{

    try
    {
        convertToInt(str);
        return 'i';
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    
    try
    {
        convertToFloat(str);
        return 'f';
    }
    catch (const std::exception &e)
    {
        (void)e;
    }

    try
    {
        convertToDouble(str);
        return 'd';
    }
    catch (const std::exception &e)
    {
        if (str.length() == 1)
            return 'c';
    }

    return -1;
}