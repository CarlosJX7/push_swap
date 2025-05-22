#include "ps_utils.h"
#include <stdio.h>

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

void ft_push(t_pila *pila_origen, t_pila *pila_destino)
{
	t_nodo *nodo_push;

	nodo_push = ft_cortar_nodo_inicio(pila_origen);
	if (nodo_push != NULL)
		ft_unir_nodo_inicio(pila_destino, nodo_push);
	else
		return ;
}

void ft_swap(t_pila *pila) // ojo al orden fifo
{
	t_nodo *nodo_primero;
	t_nodo *nodo_segundo;

	if (pila->cantidad_elementos <= 1)
	{
		return ;
	}
	
	//printf("hola");
	nodo_primero = ft_cortar_nodo_inicio(pila);
	nodo_segundo = ft_cortar_nodo_inicio(pila);
	ft_unir_nodo_inicio(pila, nodo_primero);
	ft_unir_nodo_inicio(pila, nodo_segundo);
}//moved