/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:29:12 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 17:10:20 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Base.hpp"
# include"A.hpp"
# include"B.hpp"
# include"C.hpp"

Base::~Base(){
}

Base* generate(){
   Base* instances[3] = {new A(), new B(), new C()};
    int nb = std::rand() % 3;
    return instances[nb];
}

void identify(Base* p){
    if (dynamic_cast<A*>(p)){
        std::cout << "Type: A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)){
        std::cout << "Type: B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)){
        std::cout << "Type: C" << std::endl;
    }
    else{
        std::cout << "Unknown Type" << std::endl;
    }
}

void identify(Base& p) {
    try{
        identify(&p);
    }
    catch (...){
        std::cout << "Unknown Type" << std::endl;
    }
}