/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 13:07:25 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char **av){
    try{
        if (ac > 1){
            PmergeMe pmm;
        
            /*-------Vector----------*/
            
            clock_t start_timeV = std::clock();
            int is_sortedV = pmm.init_Vect(ac, av);
            if(!is_sortedV && ac > 2){
                pmm.init_Vpairs();
                pmm.check_Vpair();
                pmm.Vmerge_sort(0, (pmm.getSize_Vect() / 2) - 1);
                pmm.init_Vfirst_Vsecond();
                pmm.init_Vjacobsthal();
                pmm._insert_Vfirst();
            }
            double durationV = ((clock() - start_timeV) * 1000000 /  CLOCKS_PER_SEC);
            pmm._printV(durationV, ac, is_sortedV);

            
            /*-------Deque----------*/

            clock_t start_timeD = std::clock();
            int is_sortedD = pmm.init_Deque(ac, av);
            if(!is_sortedD && ac > 2){
                pmm.init_Dpairs();
                pmm.check_Dpair();
                pmm.Dmerge_sort(0, (pmm.getSize_Deque() / 2) - 1);
                pmm.init_Dfirst_Dsecond();
                pmm.init_Djacobsthal();
                pmm._insert_Dfirst();
            }
            double durationD = ((clock() - start_timeD) * 1000000 /  CLOCKS_PER_SEC);
            pmm._printD(durationD, ac);
        }
        else
            throw("Error!");
    }
    catch(const char *s){
        std::cerr << s << std::endl;
    }
        
}