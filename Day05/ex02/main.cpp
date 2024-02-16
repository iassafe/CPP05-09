/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 18:59:02 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "-----------PresidentialPardonForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 4);
		PresidentialPardonForm P;
		std::cout << P;
		P.beSigned(bob);
		bob.executeForm(P);
		PresidentialPardonForm P1("President");
		P1.beSigned(bob);
		P1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "-----------RobotomyRequestForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 1);
		RobotomyRequestForm R;
		std::cout << R;
		R.beSigned(bob);
		bob.executeForm(R);
		RobotomyRequestForm R1("Robotomy");
		R1.beSigned(bob);
		R1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "-----------ShrubberyCreationForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		ShrubberyCreationForm S;
		std::cout << S;
		S.beSigned(bob);
		bob.executeForm(S);
		ShrubberyCreationForm S1("file");
		S1.beSigned(bob);
		S1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}