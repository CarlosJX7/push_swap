#include "node.h"
#include "movements.h"
// pasar siempre pila A y B
static void ft_push(t_stack *pilaA, t_stack *pilaB)
{
	t_node *nodo;
	nodo = ft_cortar_nodo(pilaA);
	if (!nodo)
		return ;
	ft_nodo_a_pila(nodo, pilaB);
}

void ft_push_a(t_stack *pilaA, t_stack *pilaB)
{
	ft_push(pilaA, pilaB);
	write(1, "pa", 2);
}

void ft_push_b(t_stack *pilaA, t_stack *pilaB)
{
	ft_push(pilaA, pilaB);
	write(1, "pb", 2);
}