/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 18:57:53 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

// std::vector<int>::iterator it = this->_vect.begin();
// it+= (i - 1);
// std::cout << *it << std::endl;

static void _isnumber(std::string str){
    size_t pos = str.find_first_not_of("0123456789");
     if (pos != std::string::npos)
        throw("Error!");
}

void PmergeMe::_merge(int left, int mid, int right){
    
}

void PmergeMe::merge_sort(int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        PmergeMe::merge_sort(left, mid);
        PmergeMe::merge_sort(mid + 1, right);
        
        PmergeMe::_merge(left, mid, right);
    }
}

PmergeMe::PmergeMe(int ac, char **av){
    for(int i=1; i < ac; i++){
        std::string str;
        if(!av[i][0])
            throw("Error!");
        str = av[i];
        _isnumber(str);
        char *endptr;
        long nb=std::strtol(av[i], &endptr, 10);
        this->_vect.push_back(nb);
    }
}

PmergeMe::PmergeMe(PmergeMe const &copy){
    *this=copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy){
    if(this!=&copy){
        this->_vect=copy._vect;
    }
    return(*this);
}

PmergeMe::~PmergeMe(){
}