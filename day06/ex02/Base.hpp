/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:14:31 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/11 10:20:38 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include<iostream>

class Base {
public:
    virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);
#endif