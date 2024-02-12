/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:28:21 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/09 18:18:42 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Serializer.hpp"

Serializer::Serializer(){
}

Serializer::~Serializer(){
}

Serializer::Serializer(Serializer const &copy){
    (void)copy;
}

Serializer &Serializer::operator=(Serializer const &copy){
    (void)copy;
    return(*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
