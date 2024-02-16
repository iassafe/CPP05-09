/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:26 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 12:18:04 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string n,
    const int g_s, const int g_e, std::string tar)
    : AForm(n, g_s, g_e), _target(tar){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
:AForm(copy){
    *this=copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{   
    if (this->getsigned() && this->getexecuting_grade() >= executor.getGrade()){
		std::ofstream	outputfile(this->_target + "_shrubbery");
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