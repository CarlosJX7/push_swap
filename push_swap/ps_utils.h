#	ifndef PS_UTILS_H
# define PS_UTILS_H

#include "nodes.h"

int		ft_atoi(const char *str);
void menu_interactivo_flechas(t_pila *pilaA, t_pila *pilaB);
int *ft_ordenar_array(int *array, int cantidad);
void ft_pila_indices(t_pila *pila, int *array_ordenado);

#endif