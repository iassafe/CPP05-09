/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 10:15:01 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr << "Error: " << s << std::endl;
    }
}