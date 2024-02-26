/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:51:30 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/26 16:06:37 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include<iostream>
#include<iterator>
#include<stack>
#include<deque>
#include<list>
#include<vector>

template <typename T,typename contr = std::deque<T> >
class	MutantStack : public std::stack<T, contr>{
	public:
		MutantStack() : std::stack<T, contr>(){};
		MutantStack(size_t size) : std::stack<T, contr>(size){};
		MutantStack(const MutantStack &obj) : std::stack<T, contr>(obj){};
		MutantStack	&operator=(const MutantStack &other){
			if (this != &other){
				std::stack<T, contr>::operator=(other);
			}
			return (*this);
		};
		~MutantStack(){};
		typedef typename std::stack<T, contr>::container_type::iterator	iterator;
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}
		typedef typename std::stack<T, contr>::container_type::const_iterator const_iterator;
		const const_iterator begin() const{
			return (this->c.begin());
		}
		const const_iterator end() const{
			return (this->c.end());
		}
};

#endif