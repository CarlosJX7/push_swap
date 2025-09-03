#include "push_swap.h"

void	ft_imprimir_pila2(t_stack *pila)
{
	t_node *nodo;

	if (pila->cantidad_elementos == 0)
		return ;
	
	nodo = pila->primer_elemento;
	while (nodo)
	{
		printf("valor >%d<, indice >%d<\n", nodo->valor, nodo->index);
		nodo = nodo->siguiente_nodo;
	}
}
/*
void	ft_tres_elementos(t_stack *pilaA, t_stack *pilaB)
{
	int	primero;
	int	segundo;

	primero = pilaA->primer_elemento->index - pilaB->cantidad_elementos;
	segundo = pilaA->primer_elemento->siguiente_nodo->index - pilaB->cantidad_elementos;
	if (primero == 0)
		write(1, "sa\nra\n", 6);
	if (primero == 1 && segundo == 0)
		write(1, "sa\n", 3);
	else if (primero == 1)
		write(1, "rra\n", 4);
	if (primero == 2 && segundo == 0)
		write(1, "ra\n", 3);
	else if (primero == 2)
		write(1, "sa\nrra\n", 7);
}
*/

void	ft_tres_elementos(t_stack *pilaA, t_stack *pilaB)
{
	int	primero;
	int	segundo;

	primero = pilaA->primer_elemento->index - pilaB->cantidad_elementos;
	segundo = pilaA->primer_elemento->siguiente_nodo->index - pilaB->cantidad_elementos;
	//printf("primero %d, segundo %d\n\n", primero, segundo);
	if (primero == 0 && segundo != 1)
	{
		ft_do_sa(pilaA);
		ft_rotate_a(pilaA);
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
	int	minimo;
	t_node *nodo;

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

void ft_movimiento(t_stack *pilaA, int minimo)
{
	if (pilaA->ultimo_elemento->index == minimo || pilaA->ultimo_elemento->anterior_nodo->index == minimo)
		ft_rotate_rev_a(pilaA);
	else
		ft_rotate_a(pilaA);
}

void	ft_cinco_elementos(t_stack *pilaA, t_stack *pilaB)
{
	t_node *nodo;
	int minimo;

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
	
	//printf("\n\npilaA %d, pilaB %d\n\n", pilaA->cantidad_elementos, pilaB->cantidad_elementos);
	//ft_imprimir_pila2(pilaA);
	//printf("\n.......\n");
	//ft_imprimir_pila2(pilaB);
	ft_tres_elementos(pilaA, pilaB);
	ft_push_a(pilaA, pilaB);
	ft_push_a(pilaA, pilaB);
}
