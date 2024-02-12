/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:49 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/09 17:51:34 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy){
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy){
    (void)copy;
    return(*this);
}

int _isdouble(std::string str)
{
    for(size_t i = 0; i < str.length(); i++){
        if (str[i] == '.')
            return (1);
    }
    return(0);
}

int    after_comma_is0(std::string str)
{
    size_t len = str.length();
    if (str[len - 1] == 'f')
        len--;
    for(size_t i = 0; i < len; i++){
        if (str[i] == '.'){
            for(size_t j = i + 1; j < len; j++){
                if (str[j] != '0')
                    return (0);
            }
        }
    }
    return (1);
}

void    convert_to_int(std::string str)
{
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])){
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    }
    else if (pseudo_literals(str)){
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void    convert_to_float(std::string str)
{
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    if (pseudo_literals(str)){
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        return ;
    }
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    else if (*endptr == '\0' && !_isdouble(str))
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    else if (_isdouble(str) && !after_comma_is0(str))
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << ".0f" <<std::endl;
}

void    convert_to_double(std::string str)
{
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    if (pseudo_literals(str)){
        std::cout << "double: " << static_cast<double>(value) << std::endl;
        return ;
    }
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    else if (*endptr == '\0' && !_isdouble(str))
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    else if (_isdouble(str) && !after_comma_is0(str))
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << ".0" <<std::endl;
}

void    convert_to_char(std::string str)
{
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        std::cout <<"char: " << "'" << static_cast<char>(str[0]) << "'" << std::endl;
    else if (pseudo_literals(str))
        std::cout << "char: impossible" << std::endl;
    else if (isprint(value))
        std::cout <<"char: " << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    convert_to_char(str);
    convert_to_int(str);
    convert_to_float(str);
    convert_to_double(str);
        
}