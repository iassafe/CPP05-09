/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:56:01 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 09:39:05 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP
# include<iostream>
# include<exception>
# include"Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool    _signed;
        const int _signing_grade;
        const int _executing_grade;

    public:
        Form();
        Form(const std::string n, bool s, const int g_s, const int g_e);
        Form(Form const &copy);
		~Form();

        Form &operator=(Form const &copy);

        std::string getname(void)const;
        int getsigning_grade(void)const;
        int getexecuting_grade(void)const;
        bool getsigned(void)const;

        void beSigned(Bureaucrat &obj);

        class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};
std::ostream &operator<<(std::ostream &output, Form const &obj);

# endif
