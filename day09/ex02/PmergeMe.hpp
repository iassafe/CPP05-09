/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:35 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 12:21:32 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<vector>
#include<iterator>

class PmergeMe{
    private:
        std::vector<int> _Vect;
        std::vector<std::pair<int, int> > _Vpairs;
        bool _Vispair;
        int _Vlast_element;
        std::vector<int> _Vfirst;
        std::vector<int> _Vsecond;
        std::vector<int> _Vjacobsthal;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        PmergeMe &operator=(PmergeMe const &copy);
        ~PmergeMe();
        
        size_t getSize_Vect() const;
        int init_Vect(int ac, char **av);
        void Vmerge_sort(int left, int right);
        void _Vmerge(int left, int mid, int right);
        void init_Vpairs(void);
        void check_Vpair(void);
        void init_Vfirst_Vsecond(void);
        void init_Vjacobsthal(void);
        void _insert_Vfirst(void);
        void _printV(double duration, int ac,int is_sorted);
};
#endif