NAME = push_swap

SRC = \
    main_prueba.c \
    main_utils.c \
    mov_push.c \
    mov_rotate.c \
    mov_rotate_rev.c \
    mov_swap.c \
    node_managment.c \
    stack_managment.c \
    utils.c \
    radix.c

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

# Opcional: para compilar un main_prueba separado.
prueba: main_prueba.c $(filter-out main.c, $(SRC))
	$(CC) $(CFLAGS) $^ -o prueba

.PHONY: all clean fclean re prueba
