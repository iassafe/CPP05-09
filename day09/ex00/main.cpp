/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 18:00:28 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string file = av[1];
            std::map<size_t, std::string> myMap;
            myMap = push_data();
            _check(file, myMap);
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr<< "Error: " << s << std::endl;
    }
}