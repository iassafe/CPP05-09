/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/03 20:17:18 by iassafe          ###   ########.fr       */
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
    for (size_t i=1; i < this->_vect.size(); i+=2){
        if (this->_vect[i] < this->_vect[i - 1])
            this->_pairs.push_back(std::make_pair(this->_vect[i - 1], this->_vect[i]));
        else
            this->_pairs.push_back(std::make_pair(this->_vect[i], this->_vect[i - 1]));
    }
}

void PmergeMe::init_first_second(void){
    this->_first.push_back(this->_pairs[0].second);
    for(size_t i=0; i < this->_pairs.size();i++){
        this->_first.push_back(this->_pairs[i].first);
    }
    for(size_t i=0; i < this->_pairs.size();i++){
        this->_second.push_back(this->_pairs[i].second);
    }
}

void PmergeMe::init_jacobsthal(void){
    this->_jacobsthal.push_back(1);
    this->_jacobsthal.push_back(3);
    for(size_t i=2; i < this->_second.size(); i++){
        int k= this->_jacobsthal[i - 1] + 2 * this->_jacobsthal[i - 2];
        this->_jacobsthal.push_back(k);
    }
}

void PmergeMe::check_pair(void){
    this->_ispair=false;
    this->_last_element=0;
    if (!(this->_vect.size()%2))
        this->_ispair=true;
    if(!this->_ispair)
        this->_last_element = this->_vect[this->_vect.size() - 1];
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
    PmergeMe::check_pair();
    PmergeMe::merge_sort(0, (this->_vect.size() / 2) - 1);
    PmergeMe::init_first_second();
    PmergeMe::init_jacobsthal();
    // std::vector<std::pair<int,int> >::iterator it = this->_pairs.begin();
    // while(it < this->_pairs.end()){
    //     std::cout << it->first << "," << it->second << std::endl;
    //     it++;
    // }
    // std::cout << _last_element << std::endl;
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

void PmergeMe::_insert_first(void){
    size_t old_js=0;
    size_t new_js=0;
    size_t n=1;
    while(n < this->_second.size()){
        size_t k =this->_jacobsthal[n];
        if (k <= this->_second.size()){
            old_js = this->_jacobsthal[n - 1];
            new_js = this->_jacobsthal[n];
        }
        else{
            old_js = this->_jacobsthal[n - 1];
            new_js = this->_second.size();
        }
        // size_t size = new_js + old_js - 1;
        // this->_first.begin() + size++,
        while(new_js > old_js){
            std::vector<int>::iterator it = this->_second.begin() + (new_js - 1);
            std::vector<int>::iterator pos = std::lower_bound(this->_first.begin(), \
            this->_first.end(), this->_second[new_js - 1]);
            this->_first.insert(pos, *it);
            new_js--;
        }
        if (new_js == this->_second.size())
            break;
        n++;
    }
    if (!this->_ispair){
        std::vector<int>::iterator pos = std::lower_bound(this->_first.begin(), \
        this->_first.end(), this->_last_element);
        this->_first.insert(pos, this->_last_element);
    }
    if(!std::is_sorted(_first.begin(), _first.end()))
        throw("mamsortinch");
}