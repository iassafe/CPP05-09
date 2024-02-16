/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:21 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 16:05:19 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include"AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string tar);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;

        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
};

# endif