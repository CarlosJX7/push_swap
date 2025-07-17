#include "node.h"
#include "movements.h"
void ft_swap(t_stack *pila)
{
	t_node *nodoA;
	t_node *nodoB;

	if (pila->cantidad_elementos <= 1)
		return ;
	
	nodoA = ft_cortar_nodo(pila);
	nodoB = ft_cortar_nodo(pila);
	ft_nodo_a_pila(nodoA, pila);
	ft_nodo_a_pila(nodoB, pila);
}

void ft_do_sa(t_stack *pilaA)
{
	ft_swap(pilaA);
	write(1, "sa", 1);
}

void ft_do_sb(t_stack *pilaB)
{
	ft_swap(pilaB);
	write(1, "sb", 1);
}

void ft_do_ss(t_stack *pilaA, t_stack *pilaB)
{
	ft_do_sa(pilaA);
	ft_do_sb(pilaB);
	write(1, "ss", 1);
}