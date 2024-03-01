/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/01 17:38:58 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

RPN::RPN(std::string str): _str(str){
}

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

void RPN::_valid_rpn(){
    std::istringstream iss(this->_str);
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

void RPN::_rpn(){
    std::istringstream iss(this->_str);
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

void RPN::_check(){
    for(size_t i = 0; i < this->_str.length(); i++){
        if (this->_str.length() > 2 ){
            if (!isdigit(this->_str[0]))
                throw("Invalid input!");
            else{
                int k = 1;
                while(this->_str[k] == ' '){
                    k++;
                }
                if(!isdigit(this->_str[k]))
                    throw("Invalid input!");
            }
        }
        if (!isdigit(this->_str[i]) && this->_str[i] != ' ' && \
            this->_str[i] != '+' && this->_str[i] != '-' && \
            this->_str[i] != '/' && this->_str[i] != '*')
            throw("Invalid input!");
        else if ((this->_str[i] == '-' || this->_str[i] == '+') && \
            (this->_str[i + 1] != ' ' && this->_str[i + 1]))
            throw("Invalid input!");
        else if (isdigit(this->_str[i]) && (this->_str[i + 1] != ' ' \
            || ( i > 0 && this->_str[i - 1] != ' ')))
            throw("Invalid input!");
        else if (((this->_str[i] == '/' || this->_str[i] == '*') \
            && (this->_str[i + 1] != ' ' && this->_str[i + 1]))
            || ((this->_str[i] == '/' || this->_str[i] == '*') \
            && this->_str[i - 1] != ' '))
            throw("Invalid input!");
    }
}