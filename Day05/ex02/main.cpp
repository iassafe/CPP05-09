/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 12:22:06 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
		std::cout << "-----------Bureaucrat-----------" << std::endl;

		try{
			Bureaucrat	bob("Bob", 88);
            std::cout << bob;
			Bureaucrat	bob1("Bob1", 0);
            std::cout << bob1;
			Bureaucrat	bob2("Bob2", 1);
            std::cout << bob2;
		}
		catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	std::cout << "-----------PresidentialPardonForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 4);
		PresidentialPardonForm P;
		P.beSigned(bob);
		bob.executeForm(P);
		PresidentialPardonForm P1("PresidentialPardonForm", 150, 150, "President1");
		P1.beSigned(bob);
		P1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------RobotomyRequestForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 1);
		RobotomyRequestForm R2;
		R2.beSigned(bob);
		bob.executeForm(R2);
		RobotomyRequestForm R3("RobotomyRequestForm", 10, 10, "Robotomy3");
		R3.beSigned(bob);
		R3.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------ShrubberyCreationForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		ShrubberyCreationForm S;
		S.beSigned(bob);
		bob.executeForm(S);
		ShrubberyCreationForm S1("ShrubberyCreationForm", 2, 2, "file");
		S1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}