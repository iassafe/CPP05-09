/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:16:41 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/14 09:36:57 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include<iostream>
#include<exception>
#include "Form.hpp"
class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int     _grade;
        
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &copy);
		~Bureaucrat();

        const std::string getname(void)const;
        int     getgrade(void)const;

		void	grade_increment(void);
		void	grade_decrement(void);
		void	signForm(Form &obj);
		
		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
    
};
std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj);


#endif