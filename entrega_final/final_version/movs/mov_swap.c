/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:06 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:13:08 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "movements.h"

static void	ft_swap(t_stack *pila)
{
	t_node	*nodo_a;
	t_node	*nodo_b;

	if (pila->cantidad_elementos <= 1)
		return ;
	nodo_a = ft_cortar_nodo(pila);
	nodo_b = ft_cortar_nodo(pila);
	ft_nodo_a_pila(nodo_a, pila);
	ft_nodo_a_pila(nodo_b, pila);
}

void	ft_do_sa(t_stack *pilaA)
{
	ft_swap(pilaA);
	write(1, "sa\n", 3);
}

void	ft_do_sb(t_stack *pilaB)
{
	ft_swap(pilaB);
	write(1, "sb\n", 3);
}

void	ft_do_ss(t_stack *pilaA, t_stack *pilaB)
{
	ft_do_sa(pilaA);
	ft_do_sb(pilaB);
	write(1, "ss\n", 3);
}
