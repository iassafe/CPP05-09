/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 12:36:56 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main(){
    try{
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    try{
        Span sp(10000);
        std::srand(std::time(0));
        for(int i = 0; i < 10000; i++){
            int nb = std::rand();
            sp.addNumber(nb);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    try{
        Span sp(5);
        sp.addNumber(-2);
        sp.addNumber(-1);
        sp.addNumber(-20);
        sp.addNumber(-91);
        sp.addNumber(-13);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    try{
        Span sp(1);
        sp.addNumber(0);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    try{
        Span sp(2);
        sp.addNumber(0);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
}