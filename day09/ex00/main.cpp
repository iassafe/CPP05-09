/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:19 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 16:17:52 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

size_t _convert(const std::string& date) {
    std::istringstream ss(date);
    size_t year, month, day;

    // Read the year, month, and day from the string stream
    char dash;
    ss >> year >> dash >> month >> dash >> day;

    // Combine the components into a single integer
    size_t result = year * 10000 + month * 100 + day;

    return result;
}
void _data(void){
    std::string line;
    std::map<int, std::string> myMap;
    std::ifstream inputFile("data.csv");
    if (!inputFile)
        throw("Opening file");
    if(!std::getline(inputFile, line))
        throw("invalid data");
    while(std::getline(inputFile, line)){
        size_t date_pos = line.find(',');
        std::string date_str = line.substr(0, date_pos);
        size_t date = _convert(date_str);
        std::cout << date << std::endl;
    }
    
}


int main(int ac, char **av){
    try{
        if (ac == 2 && av[1][0] != '\0'){
            std::string file = av[1];
            _data();
            parce_file(file);
        }
        else
            throw("Invalid param");
    }
    catch(const char *s){
        std::cerr<< "Error: " << s << std::endl;
    }
}