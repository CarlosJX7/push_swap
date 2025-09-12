/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:12:54 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:56 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

static void	ft_rotate_rev(t_stack *pila) //cortar nodo del final
{
	t_node	*nodo;

	if (pila->cantidad_elementos <= 1)
		return ;
	nodo = pila->ultimo_elemento;
	nodo->anterior_nodo->siguiente_nodo = NULL;
	pila->ultimo_elemento = nodo->anterior_nodo;
	nodo->siguiente_nodo = NULL;
	nodo->anterior_nodo = NULL;
	pila->cantidad_elementos--; 
	ft_nodo_a_pila(nodo, pila);
}

void	ft_rotate_rev_a(t_stack *pila)
{
	ft_rotate_rev(pila);
	write(1, "rra\n", 4);
}

void	ft_rotate_rev_b(t_stack *pila)
{
	ft_rotate_rev(pila);
	write(1, "rrb\n", 4);
}

void	ft_rotate_rev_r(t_stack *pilaA, t_stack *pilaB)
{
	ft_rotate_rev(pilaA);
	ft_rotate_rev(pilaB);
	write(1, "rrr\n", 4);
}
