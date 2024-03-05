/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:35 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 13:19:02 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<vector>
#include<iterator>
#include<deque>

class PmergeMe{
    private:
        /*-------Vector----------*/
        std::vector<int> _Vect;
        std::vector<std::pair<int, int> > _Vpairs;
        bool _Vispair;
        int _Vlast_element;
        std::vector<int> _Vfirst;
        std::vector<int> _Vsecond;
        std::vector<int> _Vjacobsthal;

        /*-------Deque----------*/
        std::deque<int> _Deque;
        std::deque<std::pair<int, int> > _Dpairs;
        bool _Dispair;
        int _Dlast_element;
        std::deque<int> _Dfirst;
        std::deque<int> _Dsecond;
        std::deque<int> _Djacobsthal;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        PmergeMe &operator=(PmergeMe const &copy);
        ~PmergeMe();
        
        /*-------Vector----------*/
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

        /*-------Deque----------*/
        size_t getSize_Deque() const;
        int init_Deque(int ac, char **av);
        void Dmerge_sort(int left, int right);
        void _Dmerge(int left, int mid, int right);
        void init_Dpairs(void);
        void check_Dpair(void);
        void init_Dfirst_Dsecond(void);
        void init_Djacobsthal(void);
        void _insert_Dfirst(void);
        void _printD(double duration, int ac);
};
#endif