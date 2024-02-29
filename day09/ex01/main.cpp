/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 18:20:33 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

void _check(std::string str){
    for(size_t i = 0; i < str.length(); i++){
        if ((i == 0 || i == 2) && !isdigit(str[i]))
            throw("Invalid param");
        else if (!(i%2) && isdigit(str[i]))
            
        else if ((i%2) && str[i] != ' ')
            throw("no space");
    }

    char **split = std::split(str);
}


int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string str = av[1];
            _check(str);
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr << "Error: " << s << std::endl;
    }
}