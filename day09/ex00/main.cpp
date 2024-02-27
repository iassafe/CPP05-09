/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 18:25:11 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

size_t convert_to_number(const std::string& date){
    std::istringstream ss(date);
    size_t year, month, day;

    // Read the year, month, and day from the string stream
    char dash;
    ss >> year >> dash >> month >> dash >> day;

    // Combine the components into a single integer
    size_t result = year * 10000 + month * 100 + day;

    return result;
}

std::map<size_t, std::string> push_data(void){
    std::string line;
    std::map<size_t, std::string> myMap;
    std::ifstream inputFile("data.csv");
    if (!inputFile)
        throw("Opening file");
    if(!std::getline(inputFile, line))
        throw("invalid data");
    while(std::getline(inputFile, line)){
        size_t date_pos = line.find(',');
        std::string date_str = line.substr(0, date_pos);
        std::string value = line.substr(date_pos + 1, line.length());
        size_t date = convert_to_number(date_str);
        myMap.insert(std::make_pair(date, value));
    }
    return(myMap);
}


int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string file = av[1];
            std::map<size_t, std::string> myMap;
            myMap = push_data();
            parsing(file, myMap);
            // std::map<size_t, std::string>::iterator it = myMap.begin();
            // while ( it != myMap.end()){
            //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
            //     ++it;}
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr<< "Error: " << s << std::endl;
    }
}