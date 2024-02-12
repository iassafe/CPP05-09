/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:11 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/27 13:19:21 by iassafe          ###   ########.fr       */
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
        PresidentialPardonForm(const std::string n, bool s, const int g_s,
            const int g_e, std::string tar);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();
        
        void execute(Bureaucrat const & executor) const;
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
};
#endif