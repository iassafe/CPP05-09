/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:23 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 15:29:39 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include<iostream>
#include<vector>
#include<iterator>

class Span{
    private:
        std::vector<int> _numbers;
        unsigned int N;
    public:
        Span();
        Span(unsigned int size);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

        void addNumber(int nb);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class out_of_range : public std::exception{
        public:
        	const char* what() const throw();
    };
      
};

#endif