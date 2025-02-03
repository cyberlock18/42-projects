# Variables
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx-linux/libmlx.a -lX11 -lXext -lm
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       mandelbrot.c \
       julia.c \
       minilibx-utils.c \
       color-utils.c \
       color-transform.c \
       init_fractal.c \

OBJS = $(SRCS:.c=.o)
HEADER = fractol.h

# Reglas
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
