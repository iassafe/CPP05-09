/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:16:58 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/26 16:19:35 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1){
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy){
	*this=copy;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy){ 
    if (this != &copy){
        this->_grade=copy._grade;
    }
    return(*this);
}

const std::string Bureaucrat::getname(void)const{
	return this->_name;
}

int Bureaucrat::getgrade(void)const{
	return this->_grade;
}

void Bureaucrat::grade_increment(void){
    this->_grade++;
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::grade_decrement(void){
    this->_grade--;
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low");
}

void Bureaucrat::signForm(Form &obj){
	try
	{
		obj.beSigned(*this);
		std::cout << this->getname() << " signed "
				<< obj.getname() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << this->getname() << " couldn’t sign "
			<< obj.getname() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj){
	output<< obj.getname() << ", bureaucrat grade "
			<< obj.getgrade() << std::endl; 
    return output;
}
