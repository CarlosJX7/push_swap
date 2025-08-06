#include "node.h"
#include "movements.h"

int	ft_cantidad_bits(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

void	ft_vaciar_b(t_stack *pilaA, t_stack *pilaB)
{
	while (pilaB->cantidad_elementos > 0)
	{
		ft_push_a(pilaA, pilaB);
	}
}

void	ft_algoritmo(t_stack *pilaA, t_stack *pilaB, int bit)
{
	int		contador;
	t_node	*nodo;
	int		n;

	contador = 0;
	n = pilaA->cantidad_elementos;
	while (contador < n)
	{
		nodo = pilaA->primer_elemento;
		if ((nodo->index & bit) == 0)
		{
			nodo = nodo->siguiente_nodo;
			ft_push_b(pilaA, pilaB);
		}
		else
			ft_rotate_a(pilaA);
		contador++;
	}
}

void	ft_radix(t_stack *pilaA, t_stack *pilaB)
{
	int		bit;
	int		pasadas;

	if (!pilaA->cantidad_elementos)
		return ;
	bit = 1;
	pasadas = ft_cantidad_bits(pilaA->cantidad_elementos) - 1;
	while (bit <= 1 << pasadas)
	{
		ft_algoritmo(pilaA, pilaB, bit);
		ft_vaciar_b(pilaA, pilaB);
		bit = bit << 1;
	}
}
