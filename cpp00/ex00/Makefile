# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 16:51:53 by escura            #+#    #+#              #
#    Updated: 2024/07/04 16:51:54 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = megaphone
	
CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): megaphone.cpp
	@ $(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re