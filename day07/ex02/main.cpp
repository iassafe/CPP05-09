/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:44:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/20 16:21:04 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"

int main(){
    try{
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++){
            intArray[i] = i;
        }
    
        Array<int> intArrayCopy(intArray);
        
        intArray[2] = 100;
    
        std::cout << "Original int_Array: ";
        for (unsigned int i = 0; i < intArray.size(); i++){
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    
        std::cout << "Copied int_Array: ";
        for (unsigned int i = 0; i < intArrayCopy.size(); i++){
            std::cout << intArrayCopy[i] << " ";
        }
        std::cout << std::endl;
        
        Array<std::string> stringArray(2);
        for (unsigned int i = 0; i < stringArray.size(); i++){
            stringArray[i] = "one";
        }
    
        Array<std::string> stringArrayCopy(stringArray);
        
        stringArray[1] = "two";
    
        std::cout << "Original string_Array: ";
        for (unsigned int i = 0; i < stringArray.size(); i++){
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

        stringArrayCopy[0] = "two";
        std::cout << "Copied string_Array: ";
        for (unsigned int i = 0; i < stringArrayCopy.size(); i++){
            std::cout << stringArrayCopy[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(const char *s){
        std::cout << "Error: " << s << std::endl;
    }
    return 0;
}