/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 15:54:31 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void _data(void){
    std::string line;
    std::ifstream inputFile("data.csv");
    if (!inputFile)
        throw("Opening file");
    if(!std::getline(inputFile, line))
        throw("invalid data");
    while(std::getline(inputFile, line)){
        
    }
    
}


int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string file = av[1];
            parce_file(file);
            _data();
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr<< "Error: " << s << std::endl;
    }
}