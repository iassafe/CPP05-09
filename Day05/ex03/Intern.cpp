/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:05:11 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 09:42:35 by iassafe          ###   ########.fr       */
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
    int flag = 0;
    for (int i = 0; i < 3; i ++){
        if (name == Names[i]){
            flag = 1;
            std::cout << "Intern creates " << name << std::endl;
            for (int j = 0; j < 3; j++){
                if (j != i)
                    delete ptr[j];
            }
            return (ptr[i]);
        }
    }
    if (flag == 0)
        std::cout << "Intern does not create " << name << std::endl;
    for (int i = 0; i < 3; i++){
        delete ptr[i];
    }
    return (NULL);
}