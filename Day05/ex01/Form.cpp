/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:16:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/28 18:21:45 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _signing_grade(1),
            _executing_grade(1){
    if (this->_signing_grade < 1 || this->_executing_grade)
		throw Form::GradeTooHighException();
	if (this->_signing_grade > 150 || this->_executing_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string n, bool s, const int g_s, const int g_e)
:_name(n), _signed(s), _signing_grade(g_s), _executing_grade(g_e){
    if (this->_signing_grade < 1 || this->_executing_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_signing_grade > 150 || this->_executing_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy)
: _name(copy._name), _signing_grade(copy._signing_grade),
    _executing_grade(copy._executing_grade){
    *this=copy;
}

Form::~Form(){
}

Form &Form::operator=(Form const &copy){
    if (this != &copy){
        this->_signed=copy.getsigned();
    }
    return(*this);
}

std::string Form::getname(void)const{
    return(this->_name);
}

int Form::getsigning_grade(void)const{
    return(this->_signing_grade);
}

int Form::getexecuting_grade(void)const{
    return(this->_executing_grade);
}

bool Form::getsigned(void)const{
    return(this->_signed);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

void Form::beSigned(Bureaucrat &obj)
{
    if (this->_signing_grade < obj.getgrade())
        throw Form::GradeTooLowException();
    this->_signed = true;
    
}

std::ostream &operator<<(std::ostream &output, Form const &obj){
    output << obj.getname() << ", signing grade: "
    << obj.getsigning_grade() << ", executing grade: "
    << obj.getexecuting_grade();
    if (!obj.getsigned())
        output << ", is signed";
    else
        output << ", is not signed";
    output << std::endl;
    return output;
}


