/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 16:22:49 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
	std::cout << "-----------PresidentialPardonForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		PresidentialPardonForm P;
		P.beSigned(bob);
		bob.executeForm(P);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------RobotomyRequestForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 1);
		RobotomyRequestForm R;
		R.beSigned(bob);
		bob.executeForm(R);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------ShrubberyCreationForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 150);
		ShrubberyCreationForm S;
		S.beSigned(bob);
		bob.executeForm(S);
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
		S = i.makeForm("Shrubbery", "s");
		std::cout << *S;
		std::cout << "---------------" << std::endl;
		R = i.makeForm("Robotomy", "r");
		std::cout << *R;
		std::cout << "---------------" << std::endl;
		P = i.makeForm("President", "p");
		std::cout << *P;
		std::cout << "---------------" << std::endl;
		N = i.makeForm("Naaame", "n");
		delete S;
		delete R;
		delete P;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
}