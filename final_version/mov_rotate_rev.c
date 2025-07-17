#include "node.h"
#include "movements.h"

static void	ft_rotate_rev(t_stack *pila)
{
	t_node *nodo;
	t_node *nuevo_final;

	nodo = pila->ultimo_elemento;
	nodo->anterior_nodo = NULL;
	nuevo_final = nodo->anterior_nodo;
	nuevo_final->siguiente_nodo = NULL;
	pila->ultimo_elemento = nuevo_final;
	ft_nodo_a_pila(nodo, pila);
}

void	ft_rotate_rev_a(t_stack *pila)
{
	ft_rotate_rev(pila);
	write(1, "rra", 3);
}
void	ft_rotate_rev_b(t_stack *pila)
{
	ft_rotate_rev(pila);
	write(1, "rrb", 3);
}

void	ft_rotate_rev_r(t_stack *pilaA, t_stack *pilaB)
{
	ft_rotate_rev(pilaA);
	ft_rotate_rev(pilaB);
	write(1, "rrr", 3);
}
