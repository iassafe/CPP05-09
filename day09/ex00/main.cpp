/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/24 11:17:13 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void parce_file(std::string file){
    std::string line;
    std::ifstream inputFile(file);
    if (!inputFile){
        std::cerr << "Error: Opening file" << std::endl;
        return ;
    }
    std::getline(inputFile, line);
    if (line != "date | value"){
        std::cerr << "Error: date | value" << std::endl;
        return ;
    }
    while(std::getline(inputFile, line)){
        
    }
        
}

int main(int ac, char **av){
    if (ac == 2 && av[1][0] != '\0'){
        std::string file = av[1];
        parce_file(file);
    }
}