# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 17:54:28 by tel-bouh          #+#    #+#              #
#    Updated: 2021/08/24 18:14:02 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS = ./srcs/do-op.c ./srcs/ft_operation.c

INCLUDES = ./includes

OBJ = ./srcs/do-op.o ./srcs/ft_operation.o

OUTPUTS = do-op.o ft_operation.o

PATH = ./srcs

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES) 
	mv $(OUTPUTS) $(PATH)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
