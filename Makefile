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

LIBFT = libft

NAME = fillit

FFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

SRC = ./tetrfunc.c ./main.c ./map.c ./validation.c 

LIBFT2 = libft/includes

HEADERS_DIR = includes/
INCLUDES = -I $(HEADERS_DIR)
HEADERS_LIST = tetriminos.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR = src/
SOURCES = $(addprefix $(SOURCES_DIR), $(SRC))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC))
OBJECTS_DIR = obj/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@make -C $(LIBFT)
	@gcc $(FFLAGS) -o $(NAME) $(OBJECTS) $(LFLAGS)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@gcc $(FFLAGS) -I $(LIBFT2) -o $@ -c $<

clean: 
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
