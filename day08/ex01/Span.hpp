/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:23 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 12:31:17 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include<iostream>
#include<vector>

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

    class out_of_range : public std::exception{
        public:
        	const char* what() const throw();
    };
      
};

#endif