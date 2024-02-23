/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:13 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 12:54:27 by iassafe          ###   ########.fr       */
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
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator result1 = easyfind(vec, 3);
        std::cout << "Value found at position: " << std::distance(vec.begin(), result1) << std::endl;

        std::vector<int>::iterator result2 = easyfind(vec, 7);
        std::cout << "Value found at position: " << std::distance(vec.begin(), result2) << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}