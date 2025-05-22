#include "nodes.h"
#include "ps_utils.h"

void ft_vaciar_pila(t_pila *pila)
{
	while (pila->cantidad_elementos > 0)
	{
		ft_eliminar_nodo(pila, pila->primer_elemento);
	}
}

int *ft_pila_to_array(t_pila *pila)
{
	int *lista;
	int i;
	t_nodo *posicion_pila;

	lista = malloc(sizeof(int) * pila->cantidad_elementos);
	i = 0;
	posicion_pila = pila->primer_elemento;
	while (i < pila->cantidad_elementos)
	{
		lista[i] = posicion_pila->valor;
		posicion_pila = posicion_pila->siguiente_nodo;
		i++;
	}
	return lista;
}
