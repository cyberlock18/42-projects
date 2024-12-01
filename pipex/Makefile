CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = pipex.c utils.c child.c check_error.c
OBJS = $(SRCS:.c=.o)
NAME = pipex
INCLUDES = -I $(LIBFT_DIR) -I .
GREEN = \033[32m

all: $(LIBFT) $(NAME)

$(LIBFT): 
	@ $(MAKE) header
	@ $(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)<<<<Compilacion terminada ;) -bip -bip -bop>>>>\n"
header:
	@echo "                       .,,uod8B8bou,,."
	@echo "              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:."
	@echo "         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||"
	@echo "         !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||"
	@echo "         !.......:!?|||||!!^^\"\"'            ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||  ##  PIPEX          ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||       by            ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||       ruortiz-      ||||"
	@echo "         \`.........||||                    ,||||"
	@echo "          .;.......||||               _.-!!|||||"
	@echo "   .,uodWBBBBb.....||||       _.-!!|||||||||!:'"
	@echo "!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb...."
	@echo "!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   \`."
	@echo "!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     \`."
	@echo "!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\`;:::       \`."
	@echo "!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo."
	@echo "\`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo."
	@echo "  \`..........:::::::::::::::::::::::;iof688888888888b.     \`YBBBP^'"
	@echo "    \`........::::::::::::::::;iof688888888888888888888b.     \`"
	@echo "      \`......:::::::::;iof688888888888888888888888888888b."
	@echo "        \`....:::;iof688888888888888888888888888888888899fT!"
	@echo "          \`..::!8888888888888888888888888888888899fT|!^\"'"
	@echo "            \`' !!988888888888888888888888899fT|!^\"'"
	@echo "                \`!!8888888888888888899fT|!^\"'"
	@echo "                  \`!988888888899fT|!^\"'"
	@echo "                    \`!9899fT|!^\"'"
	@echo "                      \`!^\"'"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@rm -f $(OBJS) > /dev/null 2>&1

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

%.o: %.c pipex.h
	@ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ > /dev/null 2>&1

.PHONY: all clean fclean re header