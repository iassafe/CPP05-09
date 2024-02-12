/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/12 10:03:48 by iassafe          ###   ########.fr       */
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
		Bureaucrat	bob("bob", 44);
		PresidentialPardonForm P("PresidentialPardonForm", true, 150, 150, "President");
		P.execute(bob);
		PresidentialPardonForm P1("PresidentialPardonForm", false, 150, 150, "President1");
		P1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------RobotomyRequestForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 1);
		RobotomyRequestForm R("RobotomyRequestForm", true, 10, 10, "Robotomy");
		R.execute(bob);
		RobotomyRequestForm R1("RobotomyRequestForm", true, 10, 10, "Robotomy1");
		R1.execute(bob);
		RobotomyRequestForm R2("RobotomyRequestForm", true, 10, 10, "Robotomy2");
		R2.execute(bob);
		RobotomyRequestForm R3("RobotomyRequestForm", false, 10, 10, "Robotomy3");
		R3.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------ShrubberyCreationForm--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		ShrubberyCreationForm S("ShrubberyCreationForm", true, 150, 150, "Shrubbery");
		S.execute(bob);
		ShrubberyCreationForm S1("ShrubberyCreationForm", true, 2, 2, "");
		S1.execute(bob);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	return 0;
}