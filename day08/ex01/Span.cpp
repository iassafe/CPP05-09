/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:20 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 17:43:52 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"


Span::Span() : _numbers(0), _size(0){
}

Span::Span(unsigned int size): _numbers(0){
    this->_size = size;
}

Span::Span(Span const &copy){
	*this=copy;
}

Span::~Span(){
}

Span &Span::operator=(Span const &copy){
    if (this != &copy){
        this->_numbers = copy._numbers;
        this->_size = copy._size;
    }
    return(*this);
}

void Span::addNumber(int nb){
    if (this->_numbers.size() >= this->_size)
        throw Span::out_of_range();
    this->_numbers.push_back(nb);
}

int Span::longestSpan(){
    if (this->_numbers.size() <= 1 || this->_size <= 1)
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

int Span::shortestSpan(){
    if (this->_numbers.size() <= 1 || this->_size <= 1)
        throw out_of_range();
    int min;
    min = std::abs(this->_numbers[0] - this->_numbers[1]);
    for(size_t i = 1; i < (this->_numbers.size() - 1); i++){
        if(min > abs(this->_numbers[i] - this->_numbers[i + 1]))
            min = abs(this->_numbers[i] - this->_numbers[i + 1]);
    }
    return min;
}

const char* Span::out_of_range::what() const throw(){
	return ("Problem in size");
}

