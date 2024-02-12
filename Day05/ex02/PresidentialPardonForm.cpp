/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:15 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/27 15:06:57 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", false, 25, 5), _target("default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string n, bool s,
    const int g_s, const int g_e, std::string tar)
    : AForm(n, s, g_s, g_e), _target(tar){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
:AForm(copy){
    *this=copy;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getsigned() == true && (executor.getgrade() <= this->getexecuting_grade()))
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