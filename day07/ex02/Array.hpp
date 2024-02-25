/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:58 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/25 11:04:34 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array{
    private:
        T *_elements;
        unsigned int _size;
    
    public:
        Array() : _elements(NULL), _size(0){
        }
        
        Array(unsigned int n) : _size(n){
            if(_size > 0){
                _elements = new T[_size];
                for(unsigned int i = 0; i < _size; i++){
                    _elements[i] = T();
                }
            }
            else
                _elements = NULL;
        }
    
        Array(const Array& other) : _size(other._size){
            if(_size > 0){
                _elements = new T[_size];
                for(unsigned int i = 0; i < _size; i++){
                    _elements[i] = other._elements[i];
                }
            }
            else
                _elements = NULL;
        }
    
        Array& operator=(const Array& other){
            if(this != &other){
                if (_elements)
                    delete[] _elements;
                _size = other._size;
                if (_size > 0){
                    _elements = new T[_size];
                    for(unsigned int i = 0; i < _size; i++){
                        _elements[i] = other._elements[i];
                    }
                }
                else
                    _elements = NULL;
            }
            return *this;
        }
    
        ~Array(){
            if (_elements)
                delete[] _elements;
        }
    
        T& operator[](unsigned int index){
            if(index >= _size){
                throw std::out_of_range("Index out of bounds");
            }
            return _elements[index];
        }

        const T& operator[](unsigned int index) const{
            if(index >= _size){
                throw std::out_of_range("Index out of bounds");
            }
            return _elements[index];
        }
        
        unsigned int size() const{
            return _size;
        }
};




#endif