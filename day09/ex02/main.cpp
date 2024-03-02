/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/02 18:55:35 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av){
    try{
        if (ac > 1 && av[1][0]){
            PmergeMe pmm(ac, av);
            // pmm._insert_first();
        }
        else
            throw("Error!");
    }
    catch(const char *s){
        std::cerr << s << std::endl;
    }
        
}