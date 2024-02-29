/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:18:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 15:46:05 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main(){
    try{
        Span sp(5);
        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);
        
        sp.addRange(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception& e){
        std::cerr << "Error: "<< e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    try{
        Span sp(20000);
        std::srand(std::time(0));
        for(int i = 0; i < 20000; i++){
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