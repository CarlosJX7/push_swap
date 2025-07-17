#include "node.h"

int rotaciones(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

void ft_rellenar_pila(t_stack *pilaA, t_stack *pilaB)
{
	t_node *nodo;

	if (pilaB->cantidad_elementos == 0)
	{
		return ;
	}
	
	nodo = pilaB->primer_elemento;
	while (pilaB->cantidad_elementos > 0)
	{
		
	}
	
}