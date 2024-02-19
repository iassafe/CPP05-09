/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:01:55 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/19 15:00:26 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

int main(){
    Data data;
    data.value = 6;

    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr_data = Serializer::deserialize(raw);
    std::cout << "Original data address: " << &data << std::endl;
    std::cout << "Deserialized data address: " << ptr_data << std::endl;
    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << ptr_data->value << std::endl;

    return 0;
}