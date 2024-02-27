/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:16 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 12:38:59 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<iostream>
#include<string>
#include <fstream>

void parce_file(std::string file);
void parce_date(std::string line, int end);
void parce_value(std::string value);

#endif