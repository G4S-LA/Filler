# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:25:07 by poatmeal          #+#    #+#              #
#    Updated: 2019/11/08 16:14:13 by poatmeal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

LIBFT = libft

NAME = fillit

FFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

FILES = ./tetrfunc.c ./main.c ./map.c ./validation.c 

OBJS = $(FILES:%.c=%.o)

LIBFT2 = libft/includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	gcc $(FFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	gcc $(FFLAGS) -I $(LIBFT2) -o $@ -c $<

clean: 
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
