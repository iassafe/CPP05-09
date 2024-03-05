/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 12:22:57 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av){
    try{
        if (ac > 1){
            clock_t start_time = std::clock();
            PmergeMe pmm;
            int is_sorted = pmm.init_Vect(ac, av);
            if(!is_sorted && ac > 2){
                pmm.init_Vpairs();
                pmm.check_Vpair();
                pmm.Vmerge_sort(0, (pmm.getSize_Vect() / 2) - 1);
                pmm.init_Vfirst_Vsecond();
                pmm.init_Vjacobsthal();
                pmm._insert_Vfirst();
            }
            double duration = ((clock() - start_time) * 1000000 /  CLOCKS_PER_SEC);
            pmm._printV(duration, ac, is_sorted);
        }
        else
            throw("Error!");
    }
    catch(const char *s){
        std::cerr << s << std::endl;
    }
        
}