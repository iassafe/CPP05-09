/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:37 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 10:31:16 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int main(){
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer array: ";
    ::iter<int>(intArray, 5, _print<int>);
    std::cout << std::endl;

    std::cout << "-------------" << std::endl;
    
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Double array: ";
    ::iter<double>(doubleArray, 5, _print<double>);
    std::cout << std::endl;

    std::cout << "-------------" << std::endl;
    std::string stringArray[] = {"one", "two", "three"};
    std::cout << "String array: ";
    ::iter<std::string>(stringArray, 3, _print<std::string>);
    std::cout << std::endl;

    return 0;
}