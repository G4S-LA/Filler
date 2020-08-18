# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 16:57:47 by dmetallo          #+#    #+#              #
#    Updated: 2019/11/08 14:17:27 by poatmeal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_putchar.c ft_strlen.c \
        ft_putnbr.c ft_putstr.c ft_strcpy.c \
        ft_strdup.c ft_memset.c ft_bzero.c \
        ft_strncpy.c ft_strcat.c ft_strncat.c \
        ft_strlcat.c ft_strchr.c ft_memcmp.c \
        ft_memchr.c ft_memmove.c ft_memccpy.c \
        ft_memcpy.c \
        ft_strrchr.c ft_strstr.c ft_strnstr.c \
        ft_strcmp.c ft_strncmp.c ft_isalpha.c \
        ft_isdigit.c ft_isalnum.c ft_isascii.c \
        ft_isprint.c ft_tolower.c ft_toupper.c \
        ft_memalloc.c ft_memdel.c ft_strnew.c \
        ft_strdel.c ft_strclr.c ft_striter.c \
        ft_striteri.c ft_strmap.c ft_strmapi.c \
        ft_strequ.c ft_strnequ.c ft_strsub.c \
        ft_strjoin.c ft_strtrim.c ft_strsplit.c \
        ft_itoa.c ft_putendl.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_isspace.c ft_islower.c ft_isupper.c \
		ft_numwords.c ft_isprime.c ft_sqrt.c ft_freememmass.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(INC)
	gcc -c $(FLAGS) $< -I $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
