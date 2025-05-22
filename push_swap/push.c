#include "nodes.h"
#include "movements.h"


void ft_push(t_pila *pila_origen, t_pila *pila_destino)
{
	t_nodo *nodo_push;

	nodo_push = ft_cortar_nodo_inicio(pila_origen);
	if (nodo_push != NULL)
		ft_unir_nodo_inicio(pila_destino, nodo_push);
	else
		return ;
}

void ft_do_pa(t_pila *pilaA, t_pila *pilaB)
{
	ft_push(pilaA, pilaB);
}

void ft_do_pb(t_pila *pilaA, t_pila *pilaB)
{
	ft_push(pilaB, pilaA);
}