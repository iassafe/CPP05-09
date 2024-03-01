/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:09 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 16:57:43 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

static size_t _convert(const std::string& date){
    std::istringstream s(date);
    size_t year;
    size_t month;
    size_t day;
    char dash;
    s >> year >> dash >> month >> dash >> day;
    size_t result = year * 10000 + month * 100 + day;
    return result;
}

static std::map<size_t, std::string> push_data(void){
    std::string line;
    std::map<size_t, std::string> myMap;
    std::ifstream inputFile("data.csv");
    if (!inputFile)
        throw("Could not open file.");
    if(!std::getline(inputFile, line))
        throw("Empty file.");
    while(std::getline(inputFile, line)){
        size_t date_pos = line.find(',');
        std::string date_str = line.substr(0, date_pos);
        std::string value = line.substr(date_pos + 1, line.length());
        size_t date = _convert(date_str);
        myMap.insert(std::make_pair(date, value));
    }
    return(myMap);
}

BitcoinExchange::BitcoinExchange(std::string file): _file(file){
    this->_myMap = push_data();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){
	*this=copy;
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy){
    if (this != &copy){
        this->_file = copy._file;
        this->_myMap = copy._myMap;
    }
    return(*this);
}

static int value_format(std::string value){
    int point = 0;
    for(size_t k=0; k < value.length(); k++){
        if(value[0] != ' ' || (value[k] != '-' && \
        value[k] != '+' && value[k] != ' ' \
        && value[k] != '.' && !isdigit(value[k])))
            throw("Invalid input.");
        else if (value[0] == ' ' && value[1] == '\0')
            throw("Invalid input.");
        else if ((k != 0 && value[k] == ' ') || (k != 1 && \
        (value[k] == '+' || value[k] == '-')))
            throw("Invalid input.");
        else if (((value[k] == '+' || value[k] == '-') && \
        !isdigit(value[k + 1])) || point > 1)
            throw("Invalid input.");
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

static void date_format(std::string line, int end){
    int flag = 0;
    int i = 0;
    while(i < end){
        int count = 0;
        if (!isdigit(line[0]))
            throw("Invalid input.");
        while (line[i] && line[i] != '-' && i < end && line[i] != ' '){
            if (!isdigit(line[i]))
                throw("Invalid input.");
            i++;
            count++;
        }
        if (flag == 1 || flag == 2)
            if (count != 2)
                throw("Invalid input.");
        flag++;
        i++;
    }
    if (flag != 3)
        throw("Invalid input.");
}

static int is_leap_year(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

void BitcoinExchange::ft_execute(size_t date, std::string value, std::string date_str){
    std::map<size_t, std::string>::iterator it = this->_myMap.lower_bound(date);
    if (it->first != date && it != this->_myMap.begin())
        --it;
    char *end;
    double nb_value = strtod(value.c_str(), &end);
    double it_value = strtod(it->second.c_str(), &end);
    std::cout << date_str << " => "<< value << " = " 
    << nb_value * it_value << std::endl;
}

void BitcoinExchange::check_valid_date(std::string line, int valid_value){
    size_t date_pos = line.find('|');
    if (date_pos == std::string::npos)
        date_pos = line.length();
    std::string date = line.substr(0, date_pos);
    size_t year_pos = date.find('-');
    size_t month_pos = date.find('-', year_pos + 1);
    if (year_pos == std::string::npos || month_pos == std::string::npos)
        throw ("Invalid input.");
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
        size_t nb_date = _convert(date);
        BitcoinExchange::ft_execute(nb_date, value, date);
    }
}

void BitcoinExchange::_check(void){
    std::string line;
    std::ifstream inputFile(this->_file);
    if (!inputFile)
        throw("Could not open file.");
    if(!std::getline(inputFile, line))
        throw("empty file.");
    if (line != "date | value")
        throw("date | value");
    while(std::getline(inputFile, line)){
        int end = -1;
        std::string value;
        for(size_t j = 0; j < line.length(); j++){
            if (line[j] == '|'){
                if (line[j + 1] != ' ')
                    throw("Invalid input.");
                end = j;
                value = &line[j + 1];
            }
        }
        if (end == -1)
            end = line.length();
        date_format(line, end);
        int valid_value = value_format(value);
        check_valid_date(line, valid_value);
    }  
}