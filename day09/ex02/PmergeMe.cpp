/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:30:32 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 11:12:54 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe(){
    
}

PmergeMe::PmergeMe(PmergeMe const &copy){
    *this=copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy){
    if(*this != &copy)
    {
        
    }
    return(*this);
}

PmergeMe::~PmergeMe(){
}