# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 19:15:19 by iassafe           #+#    #+#              #
#    Updated: 2024/02/12 11:20:41 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern
HEADR = AForm.hpp \
		Bureaucrat.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
		AForm.cpp \
		Bureaucrat.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all