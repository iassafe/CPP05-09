# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 14:18:57 by iassafe           #+#    #+#              #
#    Updated: 2024/02/10 10:24:04 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base
HEADR = Base.hpp A.hpp B.hpp C.hpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Base.cpp
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