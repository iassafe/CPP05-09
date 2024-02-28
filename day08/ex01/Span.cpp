/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:20 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 15:33:49 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"


Span::Span() : _numbers(0), N(0){
}

Span::Span(unsigned int size): _numbers(0), N(size){
}

Span::Span(Span const &copy){
	*this=copy;
}

Span::~Span(){
}

Span &Span::operator=(Span const &copy){
    if (this != &copy){
        this->_numbers = copy._numbers;
        this->N = copy.N;
    }
    return(*this);
}

void Span::addNumber(int nb){
    if (this->_numbers.size() >= this->N)
        throw Span::out_of_range();
    this->_numbers.push_back(nb);
}

int Span::longestSpan() const{
    if (this->_numbers.size() <= 1 || this->N <= 1)
        throw out_of_range();
    int max = this->_numbers[0];
    int min = this->_numbers[0];
    for(size_t i = 0; i < this->_numbers.size(); i++){
        if(max < this->_numbers[i])
            max = this->_numbers[i];
        if(min > this->_numbers[i])
            min = this->_numbers[i];
    }
    return (max - min);
}

int Span::shortestSpan() const{
    if (this->_numbers.size() <= 1 || this->N <= 1)
        throw out_of_range();
    std::vector<int> tmp_nbs = this->_numbers;
    std::sort(tmp_nbs.begin(), tmp_nbs.end());
    int min = (tmp_nbs[1] - tmp_nbs[0]);
    for(size_t i = 1; i < tmp_nbs.size(); i++){
        if(min > (tmp_nbs[i] - tmp_nbs[i - 1]))
            min = (tmp_nbs[i] - tmp_nbs[i - 1]);
    }
    return min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end){
        if ((this->_numbers.size() + std::distance(begin, end)) > this->N){
            throw out_of_range();
        }
        this->_numbers.insert(this->_numbers.end(), begin, end);
}

const char* Span::out_of_range::what() const throw(){
	return ("Problem in size");
}

