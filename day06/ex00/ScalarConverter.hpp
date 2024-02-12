/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:55 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/09 17:51:08 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include<iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
    	ScalarConverter(ScalarConverter const &copy);
    	ScalarConverter &operator=(ScalarConverter const &copy);
    	~ScalarConverter();
    public:
        static void convert(std::string str);
};

int pseudo_literals(std::string str);

#endif
