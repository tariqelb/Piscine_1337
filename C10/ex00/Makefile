# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 09:56:39 by tel-bouh          #+#    #+#              #
#    Updated: 2021/08/25 14:27:12 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = ./srcs/ft_display_file.c

INCLUDES = ./includes/

OBJ = ./srcs/ft_display_file.o

OUTPUTS = ft_display_file.o

PATH = ./srcs

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS) -I $(INCLUDES)
	mv $(OUTPUTS) $(PATH)
	gcc $(OBJ) -o $(NAME) -I $(INCLUDES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
