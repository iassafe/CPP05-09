/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:40 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/29 15:02:07 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
	try{

	Intern i;
	i.makeForm("Shrubbery", "a");
	i.makeForm("Robotomy", "a");
	i.makeForm("President", "a");
	i.makeForm("ffff", "a");
	}
	catch(std::exception &e){
		std::cout << "Error caught: " << e.what() << std::endl;
	}

}