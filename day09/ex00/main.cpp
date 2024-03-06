/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/06 11:21:46 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0]){
            std::string file = av[1];
            BitcoinExchange bit(file);
            bit._check();
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr<< "Error: " << s << std::endl;
    }
}