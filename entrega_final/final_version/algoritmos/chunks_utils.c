

#include "chunks_utils.h"

int	ft_stack_size(t_stack *s)
{
	if (!s)
		return (0);
	return (s->cantidad_elementos);
}

int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

int	ft_pos_of_index(t_stack *s, int target)
{
	t_node	*n;
	int		i;

	if (!s || s->cantidad_elementos == 0)
		return (-1);
	n = s->primer_elemento;
	i = 0;
	while (i < s->cantidad_elementos)
	{
		if (n->index == target)
			return (i);
		n = n->siguiente_nodo;
		i++;
	}
	return (-1);
}

int	ft_min_index_in_stack(t_stack *s)
{
	t_node	*n;
	int		i;
	int		min;

	if (!s || s->cantidad_elementos == 0)
		return (0);
	n = s->primer_elemento;
	min = n->index;
	i = 0;
	while (i < s->cantidad_elementos)
	{
		if (n->index < min)
			min = n->index;
		n = n->siguiente_nodo;
		i++;
	}
	return (min);
}

int	ft_pos_of_max_in_b(t_stack *b, int *out_max_idx)
{
	t_node	*n;
	int		i;
	int		pos_max;
	int		max_idx;

	n = b->primer_elemento;
	max_idx = n->index;
	pos_max = 0;
	i = 0;
	while (i < b->cantidad_elementos)
	{
		if (n->index > max_idx)
		{
			max_idx = n->index;
			pos_max = i;
		}
		n = n->siguiente_nodo;
		i++;
	}
	if (out_max_idx)
		*out_max_idx = max_idx;
	return (pos_max);
}

void	ft_bring_pos_to_top_a(t_stack *a, int pos)
{
	int	n;
	int	i;

	if (!a || a->cantidad_elementos <= 1 || pos < 0)
		return ;
	n = a->cantidad_elementos;
	if (pos <= n / 2)
	{
		i = 0;
		while (i++ < pos)
			ft_rotate_a(a);
	}
	else
	{
		i = 0;
		while (i++ < (n - pos))
			ft_rotate_rev_a(a);
	}
}

void	ft_bring_pos_to_top_b(t_stack *b, int pos)
{
	int	n;
	int	i;

	if (!b || b->cantidad_elementos <= 1 || pos < 0)
		return ;
	n = b->cantidad_elementos;
	if (pos <= n / 2)
	{
		i = 0;
		while (i++ < pos)
			ft_rotate_b(b);
	}
	else
	{
		i = 0;
		while (i++ < (n - pos))
			ft_rotate_rev_b(b);
	}
}

