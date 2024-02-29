/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:36:27 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/29 17:10:04 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string str = av[1];
            _check(str);
            _valid_rpn(str);
            _rpn(str);
        }
        else
            throw("Invalid param!");
    }
    catch(const char *s){
        std::cerr << "Error: " << s << std::endl;
    }
}