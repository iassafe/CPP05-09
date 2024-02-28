/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:13 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/28 11:19:07 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"

const char* notfound::what() const throw(){
	return ("Value not found in container");
}

int main(){
    try{
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(30);
        vec.push_back(4);
        vec.push_back(53);
        vec.push_back(90);
        vec.push_back(3);

        std::vector<int>::iterator result1 = easyfind(vec, 3);
        std::cout << "3 found at position: " << std::distance(vec.begin(), result1)<< std::endl;

        std::vector<int>::iterator result2 = easyfind(vec, 7);
        std::cout << "7 found at position: " << std::distance(vec.begin(), result2) << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{
        std::list<int> lst;
        lst.push_back(3);
        lst.push_back(2);
        lst.push_back(30);
        lst.push_back(4);
        lst.push_back(5);

        std::list<int>::iterator result3 = easyfind(lst, 3);
        std::cout << "3 found at position: " <<std::distance(lst.begin(), result3) << std::endl;
        
        std::list<int>::iterator result4 = easyfind(lst, 30);
        std::cout << "30 found at position: " <<std::distance(lst.begin(), result4) << std::endl;
        
        std::list<int>::iterator result5 = easyfind(lst, 5);
        std::cout << "5 found at position: " <<std::distance(lst.begin(), result5) << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}