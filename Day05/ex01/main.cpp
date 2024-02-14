/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 15:47:49 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
 
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
		catch (std::exception& e){
			std::cerr << "Error : " << e.what() << std::endl;
		}
	std::cout << "-----------Form--------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		Form		form("form", false, 150, 150);
		std::cout << form;
		bob.signForm(form);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;

	}

	std::cout << "-----------------------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 13);
		Form		form("form", true, 3, 3);
		std::cout << form;
		bob.signForm(form);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;
	try{
		Bureaucrat	bob("bob", 44);
		Form		form("form", true, 155, 10);
		bob.signForm(form);
	}
	catch(std::exception &e){
		std::cout << "Error : " << e.what() << std::endl;

	}

	return 0;
}

