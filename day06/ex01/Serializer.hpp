/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:28:25 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/09 18:17:20 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include<iostream>
#include"Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &copy);
    	Serializer &operator=(Serializer const &copy);
    	~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif