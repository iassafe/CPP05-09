# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 20:27:33 by iassafe           #+#    #+#              #
#    Updated: 2024/02/09 18:09:03 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer
HEADR = Serializer.hpp Data.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Serializer.cpp
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