/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:50:23 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/19 14:51:31 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Base.hpp"
# include"A.hpp"
# include"B.hpp"
# include"C.hpp"

Base* generate(){
    Base* instances[3] = {new A(), new B(), new C()};
    std::srand(std::time(0));
    int nb = std::rand() % 3;
    for(int i = 0; i < 3; i++){
        if (i != nb)
            delete instances[i];
    }
    return instances[nb];
}

void identify(Base* p){
    if(dynamic_cast<A*>(p)){
        std::cout << "Type: A" << std::endl;
    }
    else if(dynamic_cast<B*>(p)){
        std::cout << "Type: B" << std::endl;
    }
    else if(dynamic_cast<C*>(p)){
        std::cout << "Type: C" << std::endl;
    }
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    }
    catch(std::bad_cast& e){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    }
    catch(std::bad_cast& e){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    }
    catch(std::bad_cast& e){}
    std::cout << "Unknown type" << std::endl;
}


int main(){

    Base* instance = generate();
    identify(instance);
    identify(*instance);

    delete instance;
    return 0;
}
