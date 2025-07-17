#include "node.h"
#include "movements.h"

static	void ft_rotate(t_stack *pila)
{
	t_node *nodo;

	nodo = ft_cortar_nodo(pila);
	nodo->anterior_nodo = pila->ultimo_elemento;
	nodo->siguiente_nodo = NULL;
	pila->ultimo_elemento->siguiente_nodo = nodo;
	pila->ultimo_elemento = nodo;
}

void	ft_rotate_a(t_stack *pila)
{
	ft_rotate(pila);
	write(1, "ra", 2);
}
void	ft_rotate_b(t_stack *pila)
{
	ft_rotate(pila);
	write(1, "rb", 2);
}

void	ft_rotate_r(t_stack *pila_A, t_stack *pila_B)
{
	ft_rotate(pila_A);
	ft_rotate(pila_B);
	write(1, "rr", 2);
}
