/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/24 11:17:57 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"

int main(){
    try{
        Array<int> intArray(5);
        for(unsigned int i = 0; i < intArray.size(); i++){
            intArray[i] = i + 1;
        }
        Array<int> intArrayCopy(intArray);
        intArray[2] = 100;
    
        std::cout << "Original int_Array: ";
        for(unsigned int i = 0; i < intArray.size(); i++){
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    
        std::cout << "Copied int_Array: ";
        for(unsigned int i = 0; i < intArrayCopy.size(); i++){
            std::cout << intArrayCopy[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }


    try{
        Array<std::string> stringArray(3);
        stringArray[0] = "one";
        stringArray[1] = "two";
        stringArray[2] = "three";
        Array<std::string> stringArrayCopy(stringArray);
    
        std::cout << "Original string_Array: ";
        for(unsigned int i = 0; i < stringArray.size(); i++){
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Copied string_Array: ";
        for(unsigned int i = 0; i < stringArrayCopy.size(); i++){
            std::cout << stringArrayCopy[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}