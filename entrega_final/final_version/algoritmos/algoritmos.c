

void	ft_tres_elementos(t_stack *pilaA, t_stack *pilaB)
{
	int	primero;
	int	segundo;

	primero = pilaA->primer_elemento->index - pilaB->cantidad_elementos;
	segundo = pilaA->primer_elemento->siguiente_nodo->index - pilaB->cantidad_elementos;
	if (primero == 0 && segundo != 1)
	{
		ft_rotate_rev_a(pilaA);
		ft_do_sa(pilaA);
	}
	else if (primero == 0)
	{
		return ;
	}
	if (primero == 1 && segundo == 0)
		ft_do_sa(pilaA);
	else if (primero == 1)
		ft_rotate_rev_a(pilaA);
	if (primero == 2 && segundo == 0)
		ft_rotate_a(pilaA);
	else if (primero == 2)
	{
		ft_do_sa(pilaA);
		ft_rotate_rev_a(pilaA);
	}
}

void	ft_cuatro_elementos(t_stack *pilaA, t_stack *pilaB)
{
	int		minimo;
	t_node	*nodo;

	minimo = 0;
	while (pilaA->cantidad_elementos != 2)
	{
		nodo = pilaA->primer_elemento;
		if (nodo->index == minimo)
		{
			ft_push_b(pilaA, pilaB);
			minimo++;
		}
		ft_rotate_a(pilaA);
	}
	if (pilaA->primer_elemento->index > pilaA->ultimo_elemento->index)
		ft_do_sa(pilaA);
	ft_push_a(pilaA, pilaB);
	ft_push_a(pilaA, pilaB);
}

void	ft_movimiento(t_stack *pilaA, int minimo)
{
	if (pilaA->ultimo_elemento->index == minimo
		|| pilaA->ultimo_elemento->anterior_nodo->index == minimo)
		ft_rotate_rev_a(pilaA);
	else
		ft_rotate_a(pilaA);
}

void	ft_cinco_elementos(t_stack *pilaA, t_stack *pilaB)
{
	t_node	*nodo;
	int		minimo;

	minimo = 0;
	while (pilaB->cantidad_elementos != 2)
	{
		nodo = pilaA->primer_elemento;
		if (nodo->index == minimo)
		{
			ft_push_b(pilaA, pilaB);
			minimo++;
		}
		ft_movimiento(pilaA, minimo);
	}
	ft_tres_elementos(pilaA, pilaB);
	ft_push_a(pilaA, pilaB);
	ft_push_a(pilaA, pilaB);
}
