#include "nodes.h"
#include "movements.h"

void ft_swap(t_pila *pila) // ojo al orden fifo
{
	t_nodo *nodo_primero;
	t_nodo *nodo_segundo;

	if (pila->cantidad_elementos <= 1)
	{
		return ;
	}
	
	nodo_primero = ft_cortar_nodo_inicio(pila);
	nodo_segundo = ft_cortar_nodo_inicio(pila);
	ft_unir_nodo_inicio(pila, nodo_primero);
	ft_unir_nodo_inicio(pila, nodo_segundo);
}

void ft_do_sa(t_pila *pilaA)
{
	ft_swap(pilaA);
}

void ft_do_sb(t_pila *pilaB)
{
	ft_swap(pilaB);
}

void ft_do_ss(t_pila *pilaA, t_pila *pilaB)
{
	ft_do_sa(pilaA);
	ft_do_sb(pilaB);
}