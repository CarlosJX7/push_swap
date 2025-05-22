#include "nodes.h"
#include "movements.h"

void ft_rotate(t_pila *pila)
{
	t_nodo *nodo_nuevo_primero;
	t_nodo *nodo_antiguo_ultimo;
	t_nodo *nodo_mover;

	if (pila->cantidad_elementos <= 1)
		return ;
	nodo_mover = pila->primer_elemento;
	nodo_nuevo_primero = pila->primer_elemento->siguiente_nodo;
	nodo_antiguo_ultimo = pila->ultimo_elemento;

	nodo_nuevo_primero->anterior_nodo = NULL;
	pila->primer_elemento->siguiente_nodo = NULL;

	nodo_antiguo_ultimo->siguiente_nodo = pila->primer_elemento;
	pila->primer_elemento->anterior_nodo = nodo_antiguo_ultimo;

	pila->primer_elemento = nodo_nuevo_primero;
	pila->ultimo_elemento = nodo_mover;
}

void ft_do_ra(t_pila *pilaA)
{
	ft_rotate(pilaA);
}
void ft_do_rb(t_pila *pilaB)
{
	ft_rotate(pilaB);
}
void ft_do_rr(t_pila *pilaA, t_pila *pilaB)
{
	ft_do_ra(pilaA);
	ft_do_rb(pilaB);
}