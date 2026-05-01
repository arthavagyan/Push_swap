NAME = push_swap
BONUSNAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRC = ./Helper_functions/bench.c \
	./Helper_functions/compute_disorder.c \
	./Helper_functions/duplicate_numbers.c \
	./Helper_functions/error.c \
	./Helper_functions/operations.c \
	./Helper_functions/zero_fill_struct.c \
	./Libft/ft_atoi.c \
	./Libft/ft_calloc.c \
	./Libft/ft_split.c \
	./Libft/ft_strdup.c \
	./Libft/ft_strncmp.c \
	./Libft/node_actions.c \
	./Parser/check_and_push.c \
	./Parser/parsing.c \
	./Sorts/chunk_sort.c \
	./Sorts/radix_sort.c \
	./Sorts/selection_sort.c \
	./Sorts/small_sort_help.c \
	./Sorts/small_sort.c \
	./Sorts/sort_helper_functions.c

SRC = $(COMMON_SRC) push_swap.c
OBJS = $(SRC:.c=.o)

BONUS_SRC = $(COMMON_SRC) \
	./Checker/checker.c \
	./Checker/checker_help.c \
	./GetNextLine/get_next_line.c \
	./GetNextLine/get_next_line_utils.c

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUSNAME)

$(BONUSNAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUSNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUSNAME)

re: fclean all

.PHONY: all bonus clean fclean re