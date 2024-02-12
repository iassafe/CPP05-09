/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:05:11 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/29 14:35:12 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

AForm   *Intern::makeForm(std::string name, std::string target){
    std::string Names[] = {"Robotomy" ,"President", "Shrubbery"};
    AForm   *ptr[] = {new RobotomyRequestForm("Robotomy", true, 150, 150, target),
    new PresidentialPardonForm("President", true, 150, 150, target),
    new ShrubberyCreationForm("Shrubbery", true, 150, 150, target)};
    for (int i = 0; i < 3; i ++)
    {
        if (name == Names[i]){
            std::cout << "Intern creates " << name << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                    delete ptr[j];
            }
            return (ptr[i]);
        }

    }
    delete ptr[0];
    delete ptr[1];
    delete ptr[2];
    return (NULL);
}