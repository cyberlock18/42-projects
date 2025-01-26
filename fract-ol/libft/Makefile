# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefileproof                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 18:52:06 by ruortiz-          #+#    #+#              #
#    Updated: 2024/11/02 18:59:42 by ruortiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRC = \
	ft_strdup.c ft_calloc.c ft_strlcat.c ft_strlcpy.c \
	ft_bzero.c ft_memcpy.c ft_strlen.c ft_split.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c \
	ft_strmapi.c ft_itoa.c ft_strncmp.c ft_strtrim.c ft_strjoin.c \
	ft_substr.c ft_atoi.c ft_strnstr.c ft_memcmp.c ft_memchr.c \
	ft_memmove.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_strchr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_memset.c ft_isdigit.c \
	ft_isalpha.c ft_printf.c ft_printf_hex.c ft_printf_others.c\
	get_next_line.c get_next_line_utils.c ft_strcmp.c ft_atof.c \
	ft_is_valid_float.c

BONUS = \
	ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)
INCLUDE = libft.h
	
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJS_BONUS)
	@make $(NAME) OBJ="$(OBJ) $(OBJS_BONUS)"

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


