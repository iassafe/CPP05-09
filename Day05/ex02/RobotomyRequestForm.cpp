/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:18 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 18:47:31 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("default"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string tar)
    : AForm("RobotomyRequestForm", 72, 45), _target(tar){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
:AForm(copy){
    *this=copy;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (this->getsigned() && this->getexecuting_grade() >= executor.getGrade()){
        static bool last_exec_success = false;
        bool success = !last_exec_success;
        last_exec_success = success;
        if(success)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->_target << " robotomy failed" << std::endl;
    }
    else
        throw (AForm::GradeTooLowException());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy){
    if (this != &copy){
        AForm::operator=(copy);
        this->_target=copy._target;
    }
    return(*this);
}