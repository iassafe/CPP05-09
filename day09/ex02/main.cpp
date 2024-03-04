/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/04 17:51:37 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av){
    try{
        if (ac > 1 && av[1][0]){
            PmergeMe pmm;
            pmm.init_vect(ac, av);
            pmm.init_pairs();
            pmm.check_pair();
            pmm.merge_sort(0, (pmm.getSize_Vect() / 2) - 1);
            pmm.init_first_second();
            pmm.init_jacobsthal();
            pmm._insert_first();
        }
        else
            throw("Error!");
    }
    catch(const char *s){
        std::cerr << s << std::endl;
    }
        
}