/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:45:10 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 14:51:17 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int pseudo_literals(std::string str){
    if (str == "-inff" || str == "+inff" || str == "inff"
        || str == "+inf" || str == "inf" || str == "-inf"
        || str == "nan" || str == "+nan" || str == "-nan"
        || str == "nanf" || str == "+nanf" || str == "-nanf")
        return (1);
    return (0);
}

int _valid(std::string str){
    int flag_p = 0;
    int flag_f = 0;
    char* endptr;
    if (pseudo_literals(str) || str.length() == 1)
            return (1);
    double value = std::strtod(str.c_str(), &endptr);
    (void)value;
    if (*endptr != '\0'){
        for(size_t j = 0; j < str.length(); j++){
            if (str[j] == 'f'){
                if (str[j + 1] != '\0' || !std::isdigit(str[j - 1]))
                    return(0);
                flag_f++;
            }
            else if (str[j] == '.'){
                if (!std::isdigit(str[j + 1]) && !std::isdigit(str[j - 1]))
                    return(0);
                flag_p++;
            }
            else if (str[j] != 'f' && str[j] != '.' && !isdigit(str[j]))
                return (0);
        }
        if(flag_p != 1 && flag_f != 1)
            return(0);
    }
    return(1);
}

int main(int ac, char **av)
{
    try{
        if (ac == 2 && av[1][0] != '\0')
        {
            std::string str = av[1];
            if (_valid(str))
                ScalarConverter::convert(str);
        }
        else
            throw ("Error: invalid param");
    }
	    catch(const char *s){
	    	std::cout << s << std::endl;
	}
}
   