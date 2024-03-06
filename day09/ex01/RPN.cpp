/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2024/03/06 11:26:05 by iassafe          ###   ########.fr       */
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

static int _isvalid(std::string str){
    size_t pos = str.find_first_not_of("0123456789/*-+ ");
     if (pos != std::string::npos)
        return(0);
    return(1);
}

static int _isoper(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return(1);
    return(0);
}

void RPN::_valid_rpn(){
    int count_nb = 0;
    int count_op = 0;
    for(size_t i = 0; i < this->_str.length(); i++){
        if (isdigit(this->_str[i]))
            count_nb++;
        else if (_isoper(this->_str[i]))
            count_op++;
    }
    if (count_nb != (count_op + 1))
        throw("Invalid input!");
    
}

void RPN::_rpn(){
    std::stack<int> stack;
    int i = 0;
    while (this->_str[i]){
        if (isdigit(this->_str[i])){
            int number = static_cast<int>(this->_str[i]) - '0';
            stack.push(number);
        }
        else if (stack.size() > 1 && this->_str[i] != ' '){
            double nb1 = stack.top();
            stack.pop();
            double nb2 = stack.top();
            stack.pop();
            if (this->_str[i] == '+')
                stack.push(nb2 + nb1);
            else if(this->_str[i] == '-')
                stack.push(nb2 - nb1);
            else if(this->_str[i] == '*')
                stack.push(nb2 * nb1);
            else if(this->_str[i] == '/')
                stack.push(nb2 / nb1);
        }
        i++;
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
}


void RPN::_check(){
    if (!_isvalid(this->_str) || this->_str.length() <= 3)
        throw("Invalid input!");
    for(size_t i = 0; i < this->_str.length(); i++){
        if (!isdigit(this->_str[0]) && this->_str[0] != ' ')
            throw("Invalid input!");
        else{
            int k = 0;
            while(this->_str[k] == ' '){
                k++;
            }
            if(!isdigit(this->_str[k]))
                throw("Invalid input!");
            k++;
            while(this->_str[k] == ' '){
                k++;
            }
            if(!isdigit(this->_str[k]))
                throw("Invalid input!");
        }
        if (isdigit(this->_str[i]) && ((!_isoper(this->_str[i + 1]) && \
            this->_str[i + 1] != ' ') || ( i > 0 && !_isoper(this->_str[i - 1]) \
            && this->_str[i - 1] != ' ')))
            throw("Invalid input!");
    }
}