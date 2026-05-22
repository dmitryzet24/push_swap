.PHONY: all re clean fclean lft
FILES = push_swap.c push_swap_utils.c push_swap_utils_2.c \
		push_swap_commands.c push_swap_ops_1_3.c \
		push_swap_ops_2_3.c push_swap_ops_3_3.c \
		push_swap_compute_disorder.c push_swap_insertion.c push_swap_shell_sort.c\
		push_swap_init_stack.c push_swap_chunk_sort.c push_swap_utils_3.c
OBJS = $(FILES:.c=.o)
HEADERS = push_swap.h push_swap_2.h
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
	make clean -C libft && rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
