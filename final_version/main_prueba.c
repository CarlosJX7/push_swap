#include "node.h"
#include "stack.h"
#include "movements.h"
#include "utils.h"
#include <stdio.h>

void	ft_imprimir_pila(t_stack *pila);
int *ft_get_array(int n, char *argv[])
{
	int *array;
	int i;

	i = 0;
	array = malloc(n * sizeof(int));
	if (!array)
		return NULL;
	
	while (i < n)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return array;
}

void	ft_fill_stack(t_stack *pila, int *array, int n)
{
	int i;
	t_node *nodo;

	i = 0;
	while (i < n)
	{
		nodo = ft_crear_nodo(array[i]);
		ft_nodo_a_pila(nodo, pila);
		i++;
	}
}



int main(int argc, char *argv[])
{
	t_stack *pilaA;
	t_stack *pilaB;

	pilaA = ft_pila_ini();
	pilaB = ft_pila_ini();
	if (!pilaA || !pilaB)
		return 1;
	ft_fill_stack(pilaA, ft_get_array(argc - 1, argv), argc - 1);
	ft_imprimir_pila(pilaA);
	ft_pila_free(pilaA);
	ft_pila_free(pilaB);
	return 0;
}

void	ft_imprimir_pila(t_stack *pila)
{
	t_node *nodo;

	nodo = pila->primer_elemento;
	printf("Procedemos a imprimir la pila:\n");
	while (nodo)
	{
		printf("valor >%d<, indice >%d<\n", nodo->valor, nodo->index);
		nodo = nodo->siguiente_nodo;
	}
}
