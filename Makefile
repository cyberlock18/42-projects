# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 18:52:06 by ruortiz-          #+#    #+#              #
#    Updated: 2024/09/23 20:03:00 by ruortiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

NAME = libft.a

CC	= gcc
CFLAG = -Wall -Wextra -Werror

SRC = \
	ft_strdup.c ft_calloc.c ft_strlcat.c ft_strlcpy.c \
	ft_bzero.c ft_memcpy.c ft_strlen.c ft_split.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c \
	ft_strmapi.c ft_itoa.c ft_strncmp.c ft_strtrim.c ft_strjoin.c \
	ft_substr.c ft_atoi.c ft_strnstr.c ft_memcmp.c ft_memchr.c \
	ft_memmove.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_strchr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_memset.c ft_isdigit.c \
	ft_isalpha.c
OBJ = $(SRC:.c=.o)

INCLUDE	= libft.h
	
RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJS_BONUS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all
