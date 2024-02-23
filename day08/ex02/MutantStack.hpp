/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:51:30 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 19:36:11 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include<iostream>
#include<iterator>
#include<stack>


template <typename T>
class MutantStack{
    private:
        std::stack<T> _mystack;
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        void pop(){
            this->_mystack.pop();
        }

        T& top(){
            return this->_mystack.top();
        }

        void push(const T& value){
            this->_mystack.push(value);
        }

        size_t size() const{
            return this->_mystack.size();
        }

        iterator begin(){
            return this->_mystack.c.begin();
        }
        
        iterator end(){
            return this->_mystack.c.end();
        }
        
        
};
#endif