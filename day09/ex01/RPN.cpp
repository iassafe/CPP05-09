/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/29 11:25:21 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

void _check(std::string str){
    for(size_t i = 0; i < str.length(); i++){
        if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '+' \
            && str[i] != '-' && str[i] != '/' && str[i] != '*')
            throw("invalid param!");
    }
}