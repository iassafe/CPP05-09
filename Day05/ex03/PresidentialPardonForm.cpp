/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:15 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 11:52:07 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string n,
    const int g_s, const int g_e, std::string tar)
    : AForm(n, g_s, g_e), _target(tar){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
:AForm(copy){
    *this=copy;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->getsigned() && this->getexecuting_grade() >= executor.getGrade())
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw (AForm::GradeTooLowException());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy){
    if (this != &copy){
        AForm::operator=(copy);
        this->_target=copy._target;
    }
    return(*this);
}