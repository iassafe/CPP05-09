/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:35 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 11:33:19 by iassafe          ###   ########.fr       */
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
        int init_vect(int ac, char **av);
        void merge_sort(int left, int right);
        void _merge(int left, int mid, int right);
        void init_pairs(void);
        void check_pair(void);
        void init_first_second(void);
        void init_jacobsthal(void);
        void _insert_first(void);
        void _print(double duration, int ac,int is_sorted);
};
#endif