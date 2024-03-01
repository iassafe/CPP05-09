/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:26 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 17:06:29 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <sstream>
#include <stack>
class RPN{
    private:
        std::string _str;
    public:
        RPN(std::string str);
        RPN(RPN const &copy);
        RPN &operator=(RPN const &copy);
        ~RPN();
        void _check();
        void _rpn();
        void _valid_rpn();
};

#endif