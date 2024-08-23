# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:36:32 by escura            #+#    #+#              #
#    Updated: 2024/08/15 13:59:43 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = ex03

CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

run: all
	./$(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
