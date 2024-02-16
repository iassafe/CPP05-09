/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:16:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/26 16:25:55 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _signing_grade(1),
            _executing_grade(1){
}

AForm::AForm(const std::string n, const int g_s, const int g_e)
:_name(n), _signing_grade(g_s), _executing_grade(g_e){
    this->_signed = false;
    if (this->_signing_grade < 1 || this->_executing_grade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signing_grade > 150 || this->_executing_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy)
: _name(copy._name), _signing_grade(copy._signing_grade),
    _executing_grade(copy._executing_grade){
    *this=copy;
}

AForm::~AForm(){
}

AForm &AForm::operator=(AForm const &copy){
    if (this != &copy){
        this->_signed=copy.getsigned();
    }
    return(*this);
}

std::string AForm::getName(void)const{
    return(this->_name);
}

int AForm::getsigning_grade(void)const{
    return(this->_signing_grade);
}

int AForm::getexecuting_grade(void)const{
    return(this->_executing_grade);
}

bool AForm::getsigned(void)const{
    return(this->_signed);
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("The grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("The grade is too low");
}

void AForm::beSigned(Bureaucrat &obj){
    if (obj.getGrade() > this->getsigning_grade())
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &output, AForm const &obj){
    output << obj.getName() << ", signing grade: "
    << obj.getsigning_grade() << ", executing grade: "
    << obj.getexecuting_grade();
    if (obj.getsigned())
        output << ", is signed";
    else
        output << ", is not signed";
    output << std::endl;
    return output;
}


