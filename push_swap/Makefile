# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente y objetos
SRC = menu.c nodes_managment.c pila_managment.c ps_utils.c push.c rotate.c swap.c reverse_rotate.c  # Añade aquí todos tus .c
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
	./push_swap 10 2 30 4 50 6 70 8 90

.PHONY: all clean fclean re
