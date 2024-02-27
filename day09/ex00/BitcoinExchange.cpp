/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:09 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 12:20:02 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void parce_value(std::string value){
    int point = 0;
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

void check_leap_year(std::string line){
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
    int year = atoi(year_str.c_str());
    int month = atoi(month_str.c_str());
    int day = atoi(day_str.c_str());
    if (month < 1 || month > 12)
        throw("invalid month");
    if (day < 1 || day > 31)
        throw("invalid day");
    if (!is_leap_year(year)){
        if (month == 2 && day > 28)
            throw("invalid day");
    }
    else{
        if (month == 2 && day > 29)
            throw("invalid day");
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
        check_leap_year(line);
    }
        
}