/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:09 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 11:01:53 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void parce_value(std::string value){
    int point = 0;
        std::cout << value << std::endl;
    for(size_t k=0; k < value.length(); k++){
            if(value[0] != ' ' || (value[k] != '-' && value[k] != '+' && value[k] != ' ' && value[k] != '.' && !isdigit(value[k])))
                throw("value");
            else if (value[0] == ' ' && value[1] == '\0')
                throw("value");
            else if ((k != 0 && value[k] == ' ') || (k != 1 && (value[k] == '+' || value[k] == '-')))
                throw("value");
            else if ((value[k] == '+' || value[k] == '-') && !isdigit(value[k + 1]))
                throw("value");
            else if (value[k] == '.')
                point++;
        }
        if(point > 1)
            throw("value");
}


void parce_key(std::string line, int end){
    int flag = 0;
    int i = 0;
    while(i < end){
        int count = 0;
        if (!isdigit(line[0]))
            throw("years");
        while (line[i] && line[i] != '-' && i < end && line[i] != ' '){
            if (!isdigit(line[i]))
                throw("years");
            i++;
            count++;
        }
        if (line[i] == ' ')
            i++;
        if (flag == 1 || flag == 2)
            if (count != 2)
                throw("months or days");
        flag++;
        i++;
    }
}

void parce_file(std::string file){
    std::string line;
    std::ifstream inputFile(file);
    if (!inputFile)
        throw("Opening file");
    std::getline(inputFile, line);
    if (line != "date | value")
        throw("date | value");
    while(std::getline(inputFile, line)){
    std::cout << "line: " << line << std::endl;
        int end = -1;
        std::string value;
        for(size_t j = 0; j < line.length(); j++){
            if (line[j] == '|'){
                if (line[j + 1] != ' ')
                    throw("value");
                end = j;
                value = &line[j + 1];
            }
        }
        if (end == -1)
            end = line.length();
        parce_key(line, end);
        parce_value(value);
    }
        
}