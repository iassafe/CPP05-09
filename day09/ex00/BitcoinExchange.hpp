/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:16 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 09:40:16 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include <sstream>

void    parsing(std::string file, std::map<size_t, std::string> myMap);
void    date_format(std::string line, int end);
int     value_format(std::string value);
size_t  _convert(const std::string& date);
std::map<size_t, std::string> push_data(void);

#endif