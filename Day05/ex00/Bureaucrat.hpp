/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:16:41 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/16 14:14:42 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include<iostream>
# include<exception>

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

        const std::string getName(void)const;
        int     getGrade(void)const;

		void	grade_increment(void);
		void	grade_decrement(void);
		
		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};
    
};
std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj);


#endif