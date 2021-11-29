# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 14:06:43 by tel-bouh          #+#    #+#              #
#    Updated: 2021/08/20 11:26:45 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

INCLUDES = ./includes

OBJ = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o

OUTPUTS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

PATH = ./srcs


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c  $(SRCS) -I $(INCLUDES) 
	mv $(OUTPUTS) $(PATH)
	ar rc libft.a $(OBJ)
	ranlib libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

