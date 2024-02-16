/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:11 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 20:41:52 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include"AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
		std::string	_target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string tar);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
		    ~PresidentialPardonForm();
        
        void execute(Bureaucrat const & executor) const;
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
};
#endif