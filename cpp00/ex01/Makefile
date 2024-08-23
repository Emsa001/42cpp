# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 16:51:58 by escura            #+#    #+#              #
#    Updated: 2024/07/04 16:51:58 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = phonebook
	
CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): phonebook.cpp
	@ $(CC) $(FLAGS) phonebook.cpp -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re