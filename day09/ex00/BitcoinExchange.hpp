/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:16 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 16:57:08 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include <sstream>

class BitcoinExchange{
    private:
        std::string _file;
        std::map<size_t, std::string> _myMap;
    public:
        BitcoinExchange(std::string file);
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &copy);
        ~BitcoinExchange();
        void _check(void);
        void ft_execute(size_t date, std::string value, std::string date_str);
        void check_valid_date(std::string line, int valid_value);
};

#endif