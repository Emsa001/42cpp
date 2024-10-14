# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 18:26:17 by escura            #+#    #+#              #
#    Updated: 2024/10/14 20:48:08 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGS += -I./includes

SRC = $(wildcard src/*.cpp)
OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: $(NAME)
	clear
	./$(NAME) 5

v: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re