NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_printf.c ft_printf_others.c ft_printf_hex.c
OBJ = $(SRC:.c=.o)
AR = ar rcs


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all