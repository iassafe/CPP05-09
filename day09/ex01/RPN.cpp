/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/29 12:44:16 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

void _check(std::string str){
    for(size_t i = 0; i < str.length(); i++){
        if (str.length() > 2 ){
            if (!isdigit(str[0]))
                throw("Invalid input!");
            else{
                int k = 1;
                while(str[k] == ' '){
                    k++;
                }
                if(!isdigit(str[k]))
                    throw("Invalid input!");
            }
        }
        else if (!isdigit(str[i]) && str[i] != ' ' && \
            str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
            throw("Invalid input!");
        else if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != ' ' && str[i + 1]))
        {
            std::cout << str[i] << str[i + 1] << std::endl;
            throw("Invalid input!");
        }
        else if (isdigit(str[i]) && (str[i + 1] != ' ' || ( i > 0 && str[i + 1] != ' ')))
            throw("Invalid input!");
        else if (((str[i] == '/' || str[i] == '*') && (str[i + 1] != ' ' && str[i + 1]))
                || ((str[i] == '/' || str[i] == '*') && str[i - 1] != ' '))
                throw("Invalid input!");
    }
    std::istringstream iss(str);
    std::string token;
    char *endptr;
    while (iss >> token){
        if (isdigit(token[0])){
            double number = std::strtod(token.c_str(), &endptr);
            std::cout << "Number: " << number << std::endl;
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
            std::cout << "Operator: " << token << std::endl;
        }
    }
}