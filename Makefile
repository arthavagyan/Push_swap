NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./Helper_functions/bench.c \
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
	./Sorts/sort_helper_functions.c \
	push_swap.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f  $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re