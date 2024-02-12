# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 19:15:19 by iassafe           #+#    #+#              #
#    Updated: 2024/01/26 10:32:34 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
HEADR = Bureaucrat.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Bureaucrat.cpp main.cpp
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