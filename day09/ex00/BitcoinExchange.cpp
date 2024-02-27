/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:09 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 19:02:55 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int value_format(std::string value){
    int point = 0;
    for(size_t k=0; k < value.length(); k++){
            if(value[0] != ' ' || (value[k] != '-' && \
            value[k] != '+' && value[k] != ' ' \
            && value[k] != '.' && !isdigit(value[k])))
                throw("value");
            else if (value[0] == ' ' && value[1] == '\0')
                throw("value");
            else if ((k != 0 && value[k] == ' ') || (k != 1 && \
            (value[k] == '+' || value[k] == '-')))
                throw("value");
            else if (((value[k] == '+' || value[k] == '-') && \
            !isdigit(value[k + 1])) || point > 1)
                throw("value");
            else if (value[k] == '.')
                point++;
    }
    char *endptr;
    double val = strtod(value.c_str(), &endptr);
    if (val < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return (0);
    }
    else if (val > 1000){
        std::cerr << "Error: too large a number." << std::endl;
        return (0);
    }
    return(1);
}


void date_format(std::string line, int end){
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
        if (flag == 1 || flag == 2)
            if (count != 2)
                throw("months or days");
        flag++;
        i++;
    }
    if (flag != 3)
        throw("invalid date");
}

int is_leap_year(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}


void ft_execute(size_t date, std::string value, std::map<size_t, std::string> myMap, std::string date_str){
    // std::cout << date << " " << value << std::endl;
    std::map<size_t, std::string>::iterator it = myMap.lower_bound(date);
    it--;
    std::cout << date_str << " => "<< value << " = " << (it->second)<< std::endl;
}

void check_valid_date(std::string line, std::map<size_t, std::string> myMap, int valid_value){
    size_t date_pos = line.find('|');
    if (date_pos == std::string::npos)
        date_pos = line.length();
    std::string date = line.substr(0, date_pos);
    size_t year_pos = date.find('-');
    size_t month_pos = date.find('-', year_pos + 1);
    if (year_pos == std::string::npos || month_pos == std::string::npos)
        throw ("Invalid date");
    std::string year_str = date.substr(0, year_pos);
    std::string month_str = date.substr(year_pos + 1, month_pos - year_pos - 1);
    std::string day_str = date.substr(month_pos + 1);
    char *endptr;
    double year = strtod(year_str.c_str(), &endptr);
    double month = strtod(month_str.c_str(), &endptr);
    double day = strtod(day_str.c_str(), &endptr);
    if (month < 1 || month > 12)
        std::cerr << "Error: bad input => " << date << std::endl;
    else if (day < 1 || day > 31)
        std::cerr << "Error: bad input => " << date << std::endl;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        std::cerr << "Error: bad input => " << date << std::endl;
    else if (!is_leap_year(year) && (month == 2 && day > 28))
        std::cerr << "Error: bad input => " << date << std::endl;
    else if (is_leap_year(year) && month == 2 && day > 29)
        std::cerr << "Error: bad input => " << date << std::endl;
    else if (date_pos == line.length())
        std::cerr << "Error: bad input => " << date << std::endl;
    else if (valid_value){
        std::string value = line.substr(date_pos + 1, line.length());
        size_t nb_date = convert_to_number(date);
        ft_execute(nb_date, value, myMap, date);
    }
    
}

void parsing(std::string file, std::map<size_t, std::string> myMap){
    std::string line;
    std::ifstream inputFile(file);
    if (!inputFile)
        throw("Opening file");
    if(!std::getline(inputFile, line))
        throw("empty file");
    if (line != "date | value")
        throw("date | value");
    while(std::getline(inputFile, line)){
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
        date_format(line, end);
        int valid_value = value_format(value);
        check_valid_date(line, myMap, valid_value);
    }  
}