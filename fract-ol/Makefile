# Variables
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = /home/ruortiz-/42-projects/fract-ol/minilibx-linux/libmlx.a -lX11 -lXext -lm
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = main.c mandelbrot.c julia.c minilibx-utils.c \
	   color-utils.c
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

bonus: all

# Dependencias
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
