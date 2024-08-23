# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 16:52:13 by escura            #+#    #+#              #
#    Updated: 2024/07/04 19:37:42 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = account
	
CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): tests.cpp Account.cpp
	@ $(CC) $(FLAGS) tests.cpp Account.cpp -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re