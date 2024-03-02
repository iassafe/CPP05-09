/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/02 13:10:36 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

static void _isnumber(std::string str){
    size_t pos = str.find_first_not_of("0123456789");
     if (pos != std::string::npos)
        throw("Error!");
}

void PmergeMe::_merge(int left, int mid, int right){
    int size_vl = mid - left + 1;
    int size_vr = right - mid;
    std::vector<int> left_vec(size_vl);
    std::vector<int> right_vec(size_vr);

    for(int i=0; i < size_vl; i++){
        left_vec[i] = this->_pairs[left + i].first;
    }
    for(int i=0; i < size_vr; i++){
        right_vec[i] = this->_pairs[mid + 1 + i].first;
    }
    int i=0;
    int j=0;
    int k=left;
    while(i < size_vl && j < size_vr){
        if(left_vec[i] <= right_vec[j])
            this->_pairs[k++].first = left_vec[i++];
        else
            this->_pairs[k++].first = right_vec[j++];
    }
    while(j < size_vr){
        this->_pairs[k++].first = right_vec[j++];
    }
    while(i < size_vl){
        this->_pairs[k++].first = left_vec[i++];
    }

}

void PmergeMe::merge_sort(int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        PmergeMe::merge_sort(left, mid);
        PmergeMe::merge_sort(mid + 1, right);
        PmergeMe::_merge(left, mid, right);
    }
}

void PmergeMe::init_pairs(void){
    bool is_pair=false;
    if (!(this->_vect.size()%2))
        is_pair=true;
    int k=0;
    for (size_t i=1; i < this->_vect.size(); i+=2){
        if (this->_vect[i] > this->_vect[i - 1])
            this->_pairs.push_back(std::make_pair(this->_vect[i - 1], this->_vect[i]));
        else
            this->_pairs.push_back(std::make_pair(this->_vect[i], this->_vect[i - 1]));
        k++;
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
        if (nb > INT_MAX)
            throw("Error!");
        this->_vect.push_back(nb);
    }
    PmergeMe::init_pairs();
    PmergeMe::merge_sort(0, (this->_vect.size() / 2) - 1);
    std::vector<std::pair<int,int> >::iterator it = this->_pairs.begin();
    while(it < this->_pairs.end()){
        std::cout << it->first << "," << it->second << " ";
        it++;
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