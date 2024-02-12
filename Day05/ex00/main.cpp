/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 18:38:11 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
 
int main(void)
{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "--------exemple: grade too high--------" << std::endl << std::endl;

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
		
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--------exemple: valid grade----------" << std::endl << std::endl;
	
		try{
			Bureaucrat	bob("Bob", 88);
            std::cout << bob;
			Bureaucrat	bob1("Bob1", 120);
            std::cout << bob1;
			Bureaucrat	bob2("Bob2", 1);
            std::cout << bob2;
		}
		catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--------exemple: grade too low--------" << std::endl << std::endl;
		
		try{
			Bureaucrat	bob("Bob", 199);
            std::cout << bob;
			Bureaucrat	bob1("Bob1", 0);
            std::cout << bob1;
		}
		catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--exemple: test func grade_increment--" << std::endl << std::endl;

		try
		{
			Bureaucrat	Bob("Bob", 150);
			std::cout << Bob;
			Bob.grade_increment();
			std::cout << Bob;
		}
		catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl << std::endl;
		}

		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--exemple: test func grade_decrement--" << std::endl << std::endl;
	
		try
		{
			Bureaucrat	Bob("Bob", 2);
			std::cout << Bob;
			Bob.grade_decrement();
			std::cout << Bob;
		}
		catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	return 0;
}