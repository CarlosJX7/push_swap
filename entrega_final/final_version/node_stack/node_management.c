/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:22 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:13:24 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_managment.h"

t_node	*ft_crear_nodo(int valor)
{
	t_node	*nodo;

	nodo = malloc(sizeof(t_node));
	if (!nodo)
		return (NULL);
	nodo->anterior_nodo = NULL;
	nodo->siguiente_nodo = NULL;
	nodo->valor = valor;
	nodo->index = 0;
	return (nodo);
}

void	ft_nodo_a_pila(t_node *new_nodo, t_stack *pila)
{
	if (pila->cantidad_elementos == 0)
	{
		pila->primer_elemento = new_nodo;
		pila->ultimo_elemento = new_nodo;
	}
	else
	{
		pila->primer_elemento->anterior_nodo = new_nodo;
		new_nodo->siguiente_nodo = pila->primer_elemento;
		pila->primer_elemento = new_nodo;
	}
	new_nodo->anterior_nodo = NULL;
	pila->cantidad_elementos++;
}

t_node	*ft_cortar_nodo(t_stack *pila)
{
	t_node	*nodo;

	if (pila->cantidad_elementos == 0)
		return (NULL);
	if (pila->cantidad_elementos == 1)
	{
		nodo = pila->primer_elemento;
		pila->primer_elemento = NULL;
		pila->ultimo_elemento = NULL;
		nodo->siguiente_nodo = NULL;
		nodo->anterior_nodo = NULL;
		pila->cantidad_elementos--;
		return (nodo);
	}
	nodo = pila->primer_elemento;
	pila->primer_elemento = nodo->siguiente_nodo;
	pila->primer_elemento->anterior_nodo = NULL;
	nodo->siguiente_nodo = NULL;
	pila->cantidad_elementos--;
	return (nodo);
}

void	ft_pilas_free(t_stack *pila_a, t_stack *pila_b)
{
	ft_pila_free(pila_a);
	ft_pila_free(pila_b);
}
