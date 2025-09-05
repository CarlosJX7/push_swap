#include "push_swap.h"
#include <stdio.h>

void	ft_imprimir_pila(t_stack *pila)
{
	t_node	*nodo;

	if (pila->cantidad_elementos == 0)
		return ;
	nodo = pila->primer_elemento;
	while (nodo)
	{
		printf("valor >%d<, indice >%d<\n", nodo->valor, nodo->index);
		nodo = nodo->siguiente_nodo;
	}
}

void	ft_imprimir_pilas(t_stack *pilaA, t_stack *pilaB)
{
	printf("Imprimimos pila A (n = %d)\n", pilaA->cantidad_elementos);
	ft_imprimir_pila(pilaA);
	printf("Imprimimos pila B (n = %d)\n", pilaB->cantidad_elementos);
	ft_imprimir_pila(pilaB);
	printf("\n--------------------------\n\n");
}

void	ft_imprimir_array(int *array, int n)
{
	int	i;

	i = 0;
	printf("Imprimiendo array\n");
	while (i < n)
	{
		printf("array: %d\n", array[i]);
		i++;
	}
}
// inicio de codigo 
int ft_is_duplicate(int *array,int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == array[i])
		{
			return 1;
		}
		i++;
	}
	return (0);
}

int	*ft_get_array(int n, char *argv[])
{
	int	*array;
	int	i;
	int num;

	i = 0;
	array = malloc(n * sizeof(int));
	if (!array)
		return (NULL);
	while (i < n)
	{
		num = ft_atoi(argv[i + 1]);
		if (ft_is_duplicate(array, i, num))
		{
			free(array);
			return NULL;
		}
		array[i] = num;
		i++;
	}
	return (array);
}

void	ft_fill_stack(t_stack *pila, int *array, int n)
{
	t_node	*nodo;

	n = n - 1;
	while (n >= 0)
	{
		nodo = ft_crear_nodo(array[n]);
		ft_nodo_a_pila(nodo, pila);
		n--;
	}
	free(array);
}

int	main(int argc, char *argv[])
{
	t_stack	*pila_a;
	t_stack	*pila_b;
	int		*array;

	ft_error_check(argv, argc);
	array = ft_get_array(argc - 1, argv);
	if (!array)
		ft_print_error();
	pila_a = ft_pila_ini();
	pila_b = ft_pila_ini();
	if (!pila_a || !pila_b)
		return (1);
	ft_fill_stack(pila_a, array, argc - 1);
	array = ft_pila_to_array(pila_a);
	if (!array)
		return (0);
	array = ft_ordenar_array(array, pila_a->cantidad_elementos);
	ft_index_ordenado(pila_a, array);
	if (!ft_algoritmos(argc, pila_a, pila_b))
		ft_radix(pila_a, pila_b);
	free(array);
	ft_pila_free(pila_a);
	ft_pila_free(pila_b);
	return (0);
}
