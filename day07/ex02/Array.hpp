/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:58 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/20 16:40:50 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

#include <iostream>
#include <exception>

class Out_Of_Range: public std::exception{
	public:
		const char* what() const throw();
};

template <typename T>
class Array{
    private:
        T* _data;
        unsigned int _size;
    
    public:
        Array() : _data(NULL), _size(0){}
        
        Array(unsigned int n) : _size(n){
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++){
                _data[i] = T();
            }
        }
    
        Array(const Array& other) : _size(other._size){
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++){
                _data[i] = other._data[i];
            }
        }
    
        Array& operator=(const Array& other) {
            if (this != &other){
                delete[] _data;
                _size = other._size;
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++){
                    _data[i] = other._data[i];
                }
            }
            return *this;
        }
    
        ~Array(){
            delete[] _data;
        }
    
        T& operator[](unsigned int index){
            if (index >= _size){
                throw Out_Of_Range();
            }
            return _data[index];
        }
        
        unsigned int size() const{
            return _size;
        }
};




#endif