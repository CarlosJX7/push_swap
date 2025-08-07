#include "push_swap.h"
#include <stdio.h>

void	ft_imprimir_pila(t_stack *pila);
void	ft_imprimir_pilas(t_stack *pilaA, t_stack *pilaB);
void	ft_imprimir_array(int *array, int n);
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
	t_node *nodo;

	n = n - 1;
	while (n >= 0)
	{
		nodo = ft_crear_nodo(array[n]);
		ft_nodo_a_pila(nodo, pila);
		n--;
	}
	free(array);
}

void ft_error_check(char **argv)
{
	int	i;
	int j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "Error\n", 6);
				exit(1);
			}	
			j++;
		}
		i++;
	}
}
int main(int argc, char *argv[])
{
	t_stack *pilaA;
	t_stack *pilaB;

	ft_error_check(argv);
	pilaA = ft_pila_ini();
	pilaB = ft_pila_ini();
	if (!pilaA || !pilaB)
		return 1;
	ft_fill_stack(pilaA, ft_get_array(argc - 1, argv), argc - 1);
	ft_imprimir_pila(pilaA);
	int *array = ft_pila_to_array(pilaA);
	ft_imprimir_array(array, pilaA->cantidad_elementos);
	array = ft_ordenar_array(array, pilaA->cantidad_elementos);
	ft_imprimir_array(array, pilaA->cantidad_elementos);
	ft_index_ordenado(pilaA, array);
	ft_imprimir_pila(pilaA);
	printf("\n\n ----------Aplicamos el radix-------------\n\n");
	ft_radix(pilaA, pilaB);
	ft_imprimir_pila(pilaA);
	free(array);
	ft_pila_free(pilaA);
	ft_pila_free(pilaB);
	return 0;
}

void	ft_imprimir_pilas(t_stack *pilaA, t_stack *pilaB)
{
	printf("Imprimimos pila A (n = %d)\n", pilaA->cantidad_elementos);
	ft_imprimir_pila(pilaA);
	printf("Imprimimos pila B (n = %d)\n", pilaB->cantidad_elementos);
	ft_imprimir_pila(pilaB);
	printf("\n--------------------------\n\n");
}

void	ft_imprimir_pila(t_stack *pila)
{
	t_node *nodo;

	if (pila->cantidad_elementos == 0)
		return ;
	
	nodo = pila->primer_elemento;
	while (nodo)
	{
		printf("valor >%d<, indice >%d<\n", nodo->valor, nodo->index);
		nodo = nodo->siguiente_nodo;
	}
}

void	ft_imprimir_array(int *array, int n)
{
	int i = 0;
	printf("Imprimiendo array\n");
	while (i < n)
	{
		printf("array: %d\n", array[i]);
		i++;
	}
}
