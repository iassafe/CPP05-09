/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:29 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/29 13:53:36 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShRUBBERYCREATIONFORM_HPP
#define ShRUBBERYCREATIONFORM_HPP
#include"AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string n, bool s,
            const int g_s, const int g_e, std::string tar);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
};
#endif