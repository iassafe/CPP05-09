/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:13 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/24 18:59:02 by iassafe          ###   ########.fr       */
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
        vec.push_back(3);

        std::vector<int>::iterator result1 = easyfind(vec, 3);
        std::cout << "Value found at position: " << result1 - vec.begin()<< std::endl;

        std::vector<int>::iterator result2 = easyfind(vec, 7);
        std::cout << "Value found at position: " << result2 - vec.begin() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}