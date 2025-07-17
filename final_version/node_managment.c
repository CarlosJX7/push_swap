#include "node.h"

t_node *ft_crear_nodo(int valor)
{
	t_node *nodo;
	nodo = malloc(sizeof(t_node));
	if (!nodo)
		return NULL;
	nodo->anterior_nodo = NULL;
	nodo->siguiente_nodo = NULL;
	nodo->valor = valor;
	nodo->index = 0;
	return nodo;
}

void ft_nodo_a_pila(t_node *new_nodo, t_stack *pila)
{
	if (pila->cantidad_elementos == 0)
	{
		pila->primer_elemento = new_nodo;
	}
	else
	{
		pila->ultimo_elemento->siguiente_nodo = new_nodo;
		new_nodo->anterior_nodo = pila->ultimo_elemento;
	}
	pila->ultimo_elemento = new_nodo;
	new_nodo->siguiente_nodo = NULL;
	pila->cantidad_elementos++;
}

t_node	*ft_cortar_nodo(t_stack *pila)
{
	t_node	*nodo;
	
	nodo = pila->primer_elemento;
	pila->primer_elemento = nodo->siguiente_nodo;
	pila->primer_elemento->anterior_nodo = NULL;
	nodo->siguiente_nodo = NULL;
	nodo->anterior_nodo = NULL;
	return nodo;
}