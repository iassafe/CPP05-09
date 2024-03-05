/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/05 12:23:17 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

static void _isnumber(std::string str){
    size_t pos = str.find_first_not_of("0123456789");
     if (pos != std::string::npos)
        throw("Error!");
}

void PmergeMe::_Vmerge(int left, int mid, int right){
    int size_vl = mid - left + 1;
    int size_vr = right - mid;
    std::vector<std::pair<int, int> > left_vec(size_vl);
    std::vector<std::pair<int, int> > right_vec(size_vr);

    for (int i = 0; i < size_vl; ++i){
        left_vec[i] = this->_Vpairs[left + i];
    }
    for (int i = 0; i < size_vr; ++i){
        right_vec[i] = this->_Vpairs[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < size_vl && j < size_vr){
        if (left_vec[i].first <= right_vec[j].first)
            this->_Vpairs[k++] = left_vec[i++];
        else
            this->_Vpairs[k++] = right_vec[j++];
    }
    
    while (j < size_vr){
        this->_Vpairs[k++] = right_vec[j++];
    }
    
    while (i < size_vl){
        this->_Vpairs[k++] = left_vec[i++];
    }
}

void PmergeMe::Vmerge_sort(int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        PmergeMe::Vmerge_sort(left, mid);
        PmergeMe::Vmerge_sort(mid + 1, right);
        PmergeMe::_Vmerge(left, mid, right);
    }
}

void PmergeMe::init_Vpairs(void){
    for (size_t i=1; i < this->_Vect.size(); i+=2){
        if (this->_Vect[i] > this->_Vect[i - 1]){
            this->_Vpairs.push_back(std::make_pair(this->_Vect[i], this->_Vect[i - 1]));
        }
        else{
            this->_Vpairs.push_back(std::make_pair(this->_Vect[i - 1], this->_Vect[i]));
        }
    }
}

void PmergeMe::init_Vfirst_Vsecond(void){
    this->_Vfirst.push_back(this->_Vpairs[0].second);
    for(size_t i=0; i < this->_Vpairs.size();++i){
        this->_Vfirst.push_back(this->_Vpairs[i].first);
    }
    for(size_t i=0; i < this->_Vpairs.size();++i){
        this->_Vsecond.push_back(this->_Vpairs[i].second);
    }
}

void PmergeMe::init_Vjacobsthal(void){
    this->_Vjacobsthal.push_back(1);
    this->_Vjacobsthal.push_back(3);
    for(size_t i=2; i < this->_Vsecond.size(); ++i){
        int k= this->_Vjacobsthal[i - 1] + 2 * this->_Vjacobsthal[i - 2];
        this->_Vjacobsthal.push_back(k);
    }
}

void PmergeMe::check_Vpair(void){
    this->_Vispair=false;
    this->_Vlast_element=0;
    if (!(this->_Vect.size()%2))
        this->_Vispair=true;
    if(!this->_Vispair)
        this->_Vlast_element = this->_Vect[this->_Vect.size() - 1];
}

int PmergeMe::init_Vect(int ac, char **av){
    for(int i=1; i < ac; ++i){
        std::string str;
        if(!av[i][0])
            throw("Error!");
        str = av[i];
        _isnumber(str);
        char *endptr;
        long nb=std::strtol(av[i], &endptr, 10);
        if (nb > INT_MAX)
            throw("Error!");
        this->_Vect.push_back(nb);
    }
    if(std::is_sorted(this->_Vect.begin(), this->_Vect.end()))
        return(1);
    else
        return(0);
}

void PmergeMe::_insert_Vfirst(void){
    size_t old_js=0;
    size_t new_js=0;
    for(size_t n=1;n < this->_Vsecond.size(); ++n){
        size_t k =this->_Vjacobsthal[n];
        if (k <= this->_Vsecond.size())
            new_js = this->_Vjacobsthal[n];
        else
            new_js = this->_Vsecond.size();
        old_js = this->_Vjacobsthal[n - 1];
        size_t size_insert = new_js + old_js - 1;
        while(new_js > old_js){
            std::vector<int>::iterator pos = std::lower_bound(this->_Vfirst.begin(), \
            this->_Vfirst.begin() + size_insert, this->_Vsecond[new_js - 1]);
            this->_Vfirst.insert(pos, this->_Vsecond[new_js - 1]);
            new_js--;
        }
        if (new_js == this->_Vsecond.size())
            break;
    }
    if (!this->_Vispair){
        std::vector<int>::iterator pos = std::lower_bound(this->_Vfirst.begin(), \
        this->_Vfirst.end(), this->_Vlast_element);
        this->_Vfirst.insert(pos, this->_Vlast_element);
    }
}

void PmergeMe::_printV(double duration, int ac, int is_sorted){
    std::cout << "Before: ";
    for(size_t i=0; i < this->_Vect.size(); ++i){
        std::cout << this->_Vect[i] << " ";
    }
    if(!std::is_sorted(this->_Vfirst.begin(), this->_Vfirst.end()))
        throw("KO");
       std::cout << std::endl << "After:  ";
    if(!is_sorted){
        for(size_t i=0; i < this->_Vfirst.size(); ++i){
            std::cout << this->_Vfirst[i] << " ";
        }
    }
    else{
        for(size_t i=0; i < this->_Vect.size(); ++i){
            std::cout << this->_Vect[i] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of "<< ac - 1
    <<" elements with std::vector: " << duration << " us" << std::endl;
}

size_t PmergeMe::getSize_Vect() const{
    return(this->_Vect.size());
}

PmergeMe::PmergeMe(): _Vect(0), _Vpairs(0), _Vispair(0), \
    _Vlast_element(0), _Vfirst(0), _Vsecond(0), _Vjacobsthal(0){
}

PmergeMe::PmergeMe(PmergeMe const &copy){
    *this=copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy){
    if(this!=&copy){
        this->_Vect=copy._Vect;
    }
    return(*this);
}

PmergeMe::~PmergeMe(){
}