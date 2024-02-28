# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 10:03:35 by iassafe           #+#    #+#              #
#    Updated: 2024/02/28 10:07:17 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
HEADR = RPN.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
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