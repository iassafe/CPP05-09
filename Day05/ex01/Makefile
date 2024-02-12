# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 19:15:19 by iassafe           #+#    #+#              #
#    Updated: 2024/01/26 10:33:06 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
HEADR = Form.hpp Bureaucrat.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Bureaucrat.cpp Form.cpp main.cpp
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