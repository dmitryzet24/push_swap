.PHONY: all re clean fclean lft
FILES = push_swap.c push_swap_utils.c push_swap_utils_2.c push_swap_commands.c
OBJS = $(FILES:.c=.o)
HEADERS = push_swap.h
LFT = -L./libft -lft
LIBFT_COMPILE = make -C libft
NAME = push_swap
FLAGS = -g -Wall -Wextra -Werror
all: lft $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LFT) -o $@
%.o: %.c $(HEADERS)
	cc -c $(FLAGS) $< -o $@
lft:
	make -C libft
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
