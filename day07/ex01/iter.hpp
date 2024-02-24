/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:34 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 10:07:29 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include<iostream>

template<typename T, typename F>
void iter(T* array, size_t length, F func){
    if (!array || !length)
        return ;
    for(size_t i = 0; i < length; i++){
        func(array[i]);
    }
}

template<typename T>
void _print(const T& element){
    std::cout << element << ", ";
}
#endif