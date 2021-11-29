# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 10:59:56 by tel-bouh          #+#    #+#              #
#    Updated: 2021/08/25 14:32:01 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

SRCS = ./srcs/ft_tail.c ./srcs/ft_tail2.c

INCLUDES = ./includes/

OBJS = ./srcs/ft_tail.o ./srcs/ft_tail2.o

OUTPUTS = ft_tail.o ft_tail2.o

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
