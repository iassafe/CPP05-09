/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 11:32:59 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av){
    try{
        if (ac > 1){
            clock_t start_time = std::clock();
            PmergeMe pmm;
            int is_sorted = pmm.init_vect(ac, av);
            if(!is_sorted && ac > 2){
                pmm.init_pairs();
                pmm.check_pair();
                pmm.merge_sort(0, (pmm.getSize_Vect() / 2) - 1);
                pmm.init_first_second();
                pmm.init_jacobsthal();
                pmm._insert_first();
            }
            double duration = ((clock() - start_time) * 1000000 /  CLOCKS_PER_SEC);
            pmm._print(duration, ac, is_sorted);
        }
        else
            throw("Error!");
    }
    catch(const char *s){
        std::cerr << s << std::endl;
    }
        
}