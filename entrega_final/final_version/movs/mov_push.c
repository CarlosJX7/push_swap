/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:12:36 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:37 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "movements.h"

static int	ft_push(t_stack *pilaDonante, t_stack *pilaRecibe)
{
	t_node	*nodo;

	if (pilaDonante->cantidad_elementos == 0)
		return (0);
	nodo = ft_cortar_nodo(pilaDonante);
	if (!nodo)
		return (0);
	ft_nodo_a_pila(nodo, pilaRecibe);
	return (1);
}

void	ft_push_a(t_stack *pilaA, t_stack *pilaB)
{
	if (ft_push(pilaB, pilaA))
		write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *pilaA, t_stack *pilaB)
{
	if (ft_push(pilaA, pilaB))
		write(1, "pb\n", 3);
}
