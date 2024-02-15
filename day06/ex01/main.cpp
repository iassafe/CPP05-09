/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:01:55 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/15 16:24:09 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"


int main() {
    // Create an instance of the Data structure
    Data data;
    data.value = 5;

    // Serialize the pointer to data
    uintptr_t serialized_value = Serializer::serialize(&data);

    // Deserialize the uintptr_t back to a pointer
    Data* deserialized_data = Serializer::deserialize(serialized_value);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserialized_data == &data){
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original value: " << data.value << ", Deserialized value: " << deserialized_data->value << std::endl;
    }
    else{
        std::cerr << "Serialization and deserialization failed." << std::endl;
        std::cout << "Original value: " << data.value << ", Deserialized value: " << deserialized_data->value << std::endl;
    }

    return 0;
}