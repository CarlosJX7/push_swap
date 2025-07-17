#	ifndef STACK_H
#define STACK_H

#include "node.h"
void	ft_pila_free(t_stack *pila);
t_stack *ft_pila_ini();
int *ft_stack_to_array(t_stack *pila);

#endif