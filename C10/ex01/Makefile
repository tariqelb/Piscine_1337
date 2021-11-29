# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 19:33:05 by tel-bouh          #+#    #+#              #
#    Updated: 2021/08/25 14:29:46 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRCS = ./srcs/ft_cat.c

INCLUDES = ./includes

OBJS = ./srcs/ft_cat.o

OUTPUTS = ft_cat.o

PATH = ./srcs

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS) -I $(INCLUDES)
	mv $(OUTPUTS) $(PATH)
	gcc $(OBJS) -o $(NAME) -I $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
