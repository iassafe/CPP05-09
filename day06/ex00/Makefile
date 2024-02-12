# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 15:07:46 by iassafe           #+#    #+#              #
#    Updated: 2024/01/29 15:49:54 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
HEADR = ScalarConverter.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ScalarConverter.cpp
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