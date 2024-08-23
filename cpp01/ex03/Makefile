# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 21:06:27 by escura            #+#    #+#              #
#    Updated: 2024/08/01 21:24:29 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = ex03

CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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