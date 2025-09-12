



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:03:00 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/12 00:03:00 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"
#include "chunks_utils.h"
static void	ft_phase_push_to_b(t_stack *a, t_stack *b)
{
	int	n;
	int	window;
	int	next;
	int	idx;

	n = ft_stack_size(a);
	window = ft_isqrt(n) + 1;
	next = 0;
	while (ft_stack_size(a) > 0)
	{
		idx = a->primer_elemento->index;
		if (idx <= next)
		{
			ft_push_b(a, b);
			if (ft_stack_size(b) > 1)
				ft_rotate_b(b);
			next++;
		}
		else if (idx <= next + window)
		{
			ft_push_b(a, b);
			next++;
		}
		else
			ft_rotate_a(a);
	}
}

static void	ft_phase_pull_back_to_a(t_stack *a, t_stack *b)
{
	int	pos_max;
	int	max_idx;
	int	pos_min;
	int	min_idx;

	while (ft_stack_size(b) > 0)
	{
		pos_max = ft_pos_of_max_in_b(b, &max_idx);
		ft_bring_pos_to_top_b(b, pos_max);
		ft_push_a(a, b);
	}
	min_idx = ft_min_index_in_stack(a);
	pos_min = ft_pos_of_index(a, min_idx);
	ft_bring_pos_to_top_a(a, pos_min);
}

void	ft_chunks(t_stack *pila_a, t_stack *pila_b)
{
	if (!pila_a || pila_a->cantidad_elementos <= 1)
		return ;
	ft_phase_push_to_b(pila_a, pila_b);
	ft_phase_pull_back_to_a(pila_a, pila_b);
}
