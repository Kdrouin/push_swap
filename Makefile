NAME = push_swap
PRINTF = includes/ft_printf

SRC_DIR = src/
OBJ_DIR = obj/

COMMANDS_DIR = $(wildcard src/commands/*.c)
UTILS_DIR = $(wildcard src/utils/*.c)
SRC = $(UTILS_DIR) $(COMMANDS_DIR) src/main.c

OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(PRINTF)/libftprintf.a $(NAME)

$(PRINTF)/libftprintf.a:
	make -C $(PRINTF)
	echo "libftprintf.a created"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(PRINTF) -lftprintf

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make -C $(PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
