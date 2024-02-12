/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:56:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/01/27 11:57:10 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP
# include<iostream>
# include<exception>
# include"Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
        private:
        const std::string _name;
        bool    _signed;
        const int _signing_grade;
        const int _executing_grade;

    public:
        AForm();
        AForm(const std::string n, bool s, const int g_s, const int g_e);
        AForm(AForm const &copy);
		virtual~AForm();

        AForm &operator=(AForm const &copy);

        std::string getname(void)const;
        int getsigning_grade(void)const;
        int getexecuting_grade(void)const;
        bool getsigned(void)const;

        void beSigned(Bureaucrat &obj);
        virtual void execute(Bureaucrat const & executor) const = 0;


        class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
std::ostream &operator<<(std::ostream &output, AForm const &obj);

# endif
