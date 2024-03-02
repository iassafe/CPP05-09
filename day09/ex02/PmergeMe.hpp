/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:35 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/02 18:45:36 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<vector>
#include<iterator>

class PmergeMe{
    private:
        std::vector<int> _vect;
        std::vector<std::pair<int, int> > _pairs;
        bool _ispair;
        int _last_element;
        std::vector<int> _first;
        std::vector<int> _second;
        std::vector<int> _jacobsthal;
    public:
        PmergeMe(int ac, char **av);
        PmergeMe(PmergeMe const &copy);
        PmergeMe &operator=(PmergeMe const &copy);
        ~PmergeMe();

        void merge_sort(int left, int right);
        void _merge(int left, int mid, int right);
        void init_pairs(void);
        void check_pair(void);
        void init_first_second(void);
        void init_jacobsthal(void);
};
#endif