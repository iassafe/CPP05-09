/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 19:39:55 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
	std::cout << "-----------PresidentialPardonForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		PresidentialPardonForm P("PresidentialPardonForm", true, 150, 150, "President");
		bob.executeForm(P);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------RobotomyRequestForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 1);
		RobotomyRequestForm R("RobotomyRequestForm", true, 10, 10, "Robotomy");
		bob.executeForm(R);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------ShrubberyCreationForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		ShrubberyCreationForm S1("ShrubberyCreationForm", true, 120, 130, "");
		bob.executeForm(S1);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}
	
	std::cout << "------------------Intern--------------------" << std::endl;
	try{
		Intern i;
		AForm *S;
		AForm *R;
		AForm *P;
		AForm *N;
		Bureaucrat b;
		S = i.makeForm("Shrubbery", "a");
		std::cout << *S;
		std::cout << "---------------" << std::endl;
		R = i.makeForm("Robotomy", "a");
		std::cout << *R;
		std::cout << "---------------" << std::endl;
		P = i.makeForm("President", "a");
		std::cout << *P;
		std::cout << "---------------" << std::endl;
		N = i.makeForm("Naaame", "a");
		delete S;
		delete R;
		delete P;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
}