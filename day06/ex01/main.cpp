/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:01:55 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/09 18:23:43 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"


int main() {
    // Create an instance of the Data structure
    Data myData;
    myData.value = 42;

    // Serialize the pointer to myData
    uintptr_t serializedValue = Serializer::serialize(&myData);

    // Deserialize the uintptr_t back to a pointer
    Data* deserializedData = Serializer::deserialize(serializedValue);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedData == &myData){
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original value: " << myData.value << ", Deserialized value: " << deserializedData->value << std::endl;
    } else {
        std::cerr << "Serialization and deserialization failed." << std::endl;
    }

    return 0;
}