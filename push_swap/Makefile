# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente y objetos
SRC = menu.c nodes_managment.c pila_managment.c ps_utils.c push.c rotate.c swap.c reverse_rotate.c radix.c  # Añade aquí todos tus .c
OBJ = $(SRC:.c=.o)

# Nombre del ejecutable
NAME = push_swap

# Regla principal
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objetos y ejecutable
clean:
	rm -f *.o push_swap

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	./push_swap 90 80 70 60 50 40 30 20 10 0

run2:
	./push_swap 0 1 2 3 4 5 6 7 8 9

.PHONY: all clean fclean re
