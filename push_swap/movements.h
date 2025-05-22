#	ifndef MOVEMENTS_H
# define MOVEMENTS_H

#include "nodes.h"

void ft_rotate(t_pila *pila);
void ft_rotate_inverso(t_pila *pila);

void ft_push(t_pila *pila_origen, t_pila *pila_destino);
void ft_do_pa(t_pila *pilaA, t_pila *pilaB);
void ft_swap(t_pila *pila);
//ojo a los casos especiales


#endif
