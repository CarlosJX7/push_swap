/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:12:44 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:45 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static void	ft_rotate(t_stack *pila)
{
	t_node	*nodo;
	t_node	*fin;

	if (pila->cantidad_elementos <= 1)
		return ;
	nodo = ft_cortar_nodo(pila);
	fin = pila->ultimo_elemento;
	fin->siguiente_nodo = nodo;
	nodo->anterior_nodo = fin;
	nodo->siguiente_nodo = NULL;
	pila->ultimo_elemento = nodo;
	pila->cantidad_elementos++;
}

void	ft_rotate_a(t_stack *pila)
{
	ft_rotate(pila);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack *pila)
{
	ft_rotate(pila);
	write(1, "rb\n", 3);
}

void	ft_rotate_r(t_stack *pila_A, t_stack *pila_B)
{
	ft_rotate(pila_A);
	ft_rotate(pila_B);
	write(1, "rr\n", 3);
}
