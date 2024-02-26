/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/26 19:08:49 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void parce_value(std::string value){
    int point = 0;
    for(size_t k=0; k < value.length(); k++){
            if(!isdigit(value[0]) || (value[k] != '.' && !isdigit(value[k]))){
                throw("Error value");
                    return ;
            }
            if (value[k] == '.')
                point++;
        }
        if(point > 1){
            throw("Error value");
            return ;
        }
}


void parce_key(std::string line, int end){
    int flag = 0;
    int i = 0;
    while(i < end){
        int count = 0;
        if (!isdigit(line[0])){
            throw("Error years");
                return ;
        }
        while (line[i] && line[i] != '-' && i < end){
            if (!isdigit(line[i])){
                throw("Error years");
                return ;
            }
            i++;
            count++;
        }
        if (flag == 1 || flag == 2)
            if (count != 2){
                throw("Error months or days");
                return ;
            }
        flag++;
        i++;
    }
}

void parce_file(std::string file){
    std::string line;
    std::ifstream inputFile(file);
    if (!inputFile){
        throw("Error: Opening file");
        return ;
    }
    std::getline(inputFile, line);
    if (line != "date | value"){
        throw("Error: date | value");
        return ;
    }
    while(std::getline(inputFile, line)){
    std::cout << "line: " << line << std::endl;
        int end = -1;
        std::string value;
        std::cout << value << std::endl;
        for(size_t j = 0; j < line.length(); j++){
            if (line[j] == ',')
            {
                end = j;
                value = &line[j + 1];
            }
        }
        std::cout << value << std::endl;
        if (end == -1)
            end = line.length();
        parce_key(line, end);
        parce_value(value);
    }
        
}

int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string file = av[1];
            parce_file(file);
        }
        else
            throw("Error: ");
        
    }
    catch(const char *s){
        std::cout << s << std::endl;
    }
}