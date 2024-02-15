/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:26 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/15 13:09:01 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", false, 145, 137), _target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string n, bool s,
    const int g_s, const int g_e, std::string tar)
    : AForm(n, s, g_s, g_e), _target(tar){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
:AForm(copy){
    *this=copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{   
    if (this->getsigned() && this->getexecuting_grade() >= executor.getgrade()){
		std::ofstream	outputfile(this->_target);
		if (!outputfile.is_open()){
			std::cerr << "Error: creating file!" << std::endl;
			return ;
		}
        std::cout << this->_target << " is open" << std::endl;
		outputfile << "   *\n"
                   << "  ***\n"
                   << " *****\n"
                   << "*******\n"
                   << "   ||\n"
                   << "   ||\n";
        outputfile.close();
    }
	else
		throw (AForm::GradeTooLowException());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy){
    if (this != &copy){
        AForm::operator=(copy);
        this->_target=copy._target;
    }
    return(*this);
}