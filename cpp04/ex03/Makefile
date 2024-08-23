# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 13:20:49 by escura            #+#    #+#              #
#    Updated: 2024/08/19 19:24:32 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: $(NAME)
	clear
	./$(NAME)

v: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re
