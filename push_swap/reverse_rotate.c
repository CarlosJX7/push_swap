#include "nodes.h"
#include "movements.h"

void ft_rotate_inverso(t_pila *pila)
{
	t_nodo *nodo_nuevo_ultimo;
	t_nodo *nodo_antiguo_primero;
	t_nodo *nodo_mover;

	if (pila->cantidad_elementos <= 1)
		return ;
	
	nodo_nuevo_ultimo = pila->ultimo_elemento->anterior_nodo;
	nodo_antiguo_primero = pila->primer_elemento;
	nodo_mover = pila->ultimo_elemento;

	// Separamos los nodos del final
	nodo_nuevo_ultimo->siguiente_nodo = NULL;
	nodo_mover->anterior_nodo = NULL;

	nodo_mover->siguiente_nodo = nodo_antiguo_primero;
	nodo_antiguo_primero->anterior_nodo = nodo_mover;

	pila->primer_elemento = nodo_mover;
	pila->ultimo_elemento = nodo_nuevo_ultimo;
}

void ft_do_rra(t_pila *pilaA)
{
	ft_rotate_inverso(pilaA);
}
void ft_do_rrb(t_pila *pilaB)
{
	ft_rotate_inverso(pilaB);
}
void ft_do_rrr(t_pila *pilaA, t_pila *pilaB)
{
	ft_do_rra(pilaA);
	ft_do_rrb(pilaB);
}