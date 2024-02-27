/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:10 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/27 16:02:36 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include<iostream>
#include<vector>
#include<list>

class notfound : public std::exception{
    public:
		const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw notfound();
    return it;  
}

#endif
