/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:52:14 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/26 16:08:27 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(4);
    mstack.push(9);
    mstack.push(17);
    mstack.push(20);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite){
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "--------------------------" << std::endl;
    const MutantStack<int> const_mstack;
    MutantStack<int>::const_iterator const_it = const_mstack.begin();
    MutantStack<int>::const_iterator const_ite = const_mstack.end();
    if (const_it != const_ite)
        std::cout << *const_it << std::endl;
    else
        std::cout << "const_mstack is empty" << std::endl;

    std::cout << "--------------------------" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size: " <<lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    std::list<int>::iterator itt = lst.begin();
    std::list<int>::iterator itte = lst.end();
    ++itt;
    --itt;
    std::cout << "Elements of list lst: " << std::endl;
    while (itt != itte){
        std::cout << *itt << std::endl;
        ++itt;
    }

    std::cout << "--------------------------" << std::endl;
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << "top: " << vec.back() << std::endl;
    vec.pop_back();
    std::cout << "size: " << vec.size() << std::endl;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    std::vector<int>::iterator it_vec = vec.begin();
    std::vector<int>::iterator ite_vec = vec.end();
    ++it_vec;
    --it_vec;
    std::cout << "Elements of vector vec: " << std::endl;
    while (it_vec != ite_vec){
        std::cout << *it_vec << std::endl;
        ++it_vec;
    }
    return 0;
}
