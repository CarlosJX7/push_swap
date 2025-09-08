#include "stack.h"
#include "node.h"
#include "push_swap.h"

t_stack	*ft_pila_ini(void)
{
	t_stack	*pila;

	pila = malloc(sizeof(t_stack));
	if (!pila)
		return (NULL);
	pila->cantidad_elementos = 0;
	pila->primer_elemento = NULL;
	pila->ultimo_elemento = NULL;
	return (pila);
}

int	*ft_stack_to_array(t_stack *pila)
{
	int		i;
	int		*array;
	t_node	*nodo;

	nodo = pila->primer_elemento;
	array = malloc(pila->cantidad_elementos * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < pila->cantidad_elementos && nodo)
	{
		array[i] = nodo->valor;
		nodo = nodo->siguiente_nodo;
		i++;
	}
	return (array);
}

void	ft_pila_free(t_stack *pila)
{
	t_node	*nodo;
	t_node	*siguiente;

	if (pila->cantidad_elementos == 0)
	{
		free(pila);
		return ;
	}
	nodo = pila->primer_elemento;
	while (pila->cantidad_elementos)
	{
		siguiente = nodo->siguiente_nodo;
		free(nodo);
		pila->cantidad_elementos--;
		nodo = siguiente;
	}
	pila->primer_elemento = NULL;
	pila->ultimo_elemento = NULL;
	free(pila);
}

int	ft_array_ordenado_check(int *array, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_pila_to_array(t_stack *pila)
{
	int		*array;
	int		i;
	t_node	*posicion;

	array = malloc(pila->cantidad_elementos * sizeof(int));
	if (!array)
		return (NULL);
	posicion = pila->primer_elemento;
	i = 0;
	while (i < pila->cantidad_elementos)
	{
		array[i] = posicion->valor;
		posicion = posicion->siguiente_nodo;
		i++;
	}
	if (ft_array_ordenado_check(array, pila->cantidad_elementos))
		return (array);
	else
		return (NULL);
}
