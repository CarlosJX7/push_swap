NAME = push_swap

SRC = \
    algoritmos/algoritmos.c \
    algoritmos/radix.c \
    main/main_utils.c \
    main/minilibft.c \
    main/push_swap.c \
    main/utils.c \
    movs/mov_push.c \
    movs/mov_rotate.c \
    movs/mov_rotate_rev.c \
    movs/mov_swap.c \
    node_stack/node_management.c \
    node_stack/stack_management.c \
    parsing/parsing.c \
    parsing/get_string.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re prueba
