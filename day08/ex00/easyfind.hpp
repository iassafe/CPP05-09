/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:10 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/23 12:46:31 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include<iostream>
#include<vector>

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
