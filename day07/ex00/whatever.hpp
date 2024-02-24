/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:31:42 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/24 12:07:31 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include<iostream>

template <typename T>
void swap(T& a, T& b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}   

template <typename T>
T min(const T& a, const T& b){
    if (b <= a)
        return b;
    return a;
}

template <typename T>
T max(const T& a, const T& b){
    if(b >= a)
        return b;
    return a;
}
#endif
