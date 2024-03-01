/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 10:41:43 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

RPN::RPN(RPN const &copy){
	*this=copy;
}

RPN::~RPN(){
}

RPN &RPN::operator=(RPN const &copy){
    if (this != &copy){
        this->_str = copy._str;
    }
    return(*this);
}

static void _valid_rpn(std::string str){
    std::istringstream iss(str);
    std::string token;
    int count_nb = 0;
    int count_op = 0;
    while (iss >> token){
        if (isdigit(token[0]))
            count_nb++;
        else if(token == "+" || token == "-" || token == "/" || token == "*")
            count_op++;
    }
    if (count_nb != (count_op + 1))
        throw("Invalid input!");
    
}

static void _rpn(std::string str){
    std::istringstream iss(str);
    std::string token;
    char *endptr;
    std::stack<int> stack;
    while (iss >> token){
        if (isdigit(token[0])){
            double number = std::strtod(token.c_str(), &endptr);
            stack.push(number);
        }
        else if (stack.size() > 1){
            double nb1 = stack.top();
            stack.pop();
            double nb2 = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(nb2 + nb1);
            else if(token == "-")
                stack.push(nb2 - nb1);
            else if(token == "*")
                stack.push(nb2 * nb1);
            else if(token == "/")
                stack.push(nb2 / nb1);
        }
        else
            throw("Invalid input!");
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
}

static void _check(std::string str){
    for(size_t i = 0; i < str.length(); i++){
        if (str.length() > 2 ){
            if (!isdigit(str[0]))
                throw("Invalid input!");
            else{
                int k = 1;
                while(str[k] == ' '){
                    k++;
                }
                if(!isdigit(str[k]))
                    throw("Invalid input!");
            }
        }
        if (!isdigit(str[i]) && str[i] != ' ' && \
            str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
            throw("Invalid input!");
        else if ((str[i] == '-' || str[i] == '+') && (str[i + 1] != ' ' && str[i + 1]))
            throw("Invalid input!");
        else if (isdigit(str[i]) && (str[i + 1] != ' ' || ( i > 0 && str[i - 1] != ' ')))
            throw("Invalid input!");
        else if (((str[i] == '/' || str[i] == '*') && (str[i + 1] != ' ' && str[i + 1]))
                || ((str[i] == '/' || str[i] == '*') && str[i - 1] != ' '))
            throw("Invalid input!");
    }
}

RPN::RPN(std::string str): _str(str){
	_check(this->_str);
    _valid_rpn(this->_str);
    _rpn(this->_str);
}