/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:21 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 11:29:14 by iassafe          ###   ########.fr       */
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
        RobotomyRequestForm(const std::string n, const int g_s,
            const int g_e, std::string tar);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;

        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
};

# endif