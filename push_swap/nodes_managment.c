#include "nodes.h"


void ft_agregar_nodo(t_pila *pila, int valor_main)
{
	t_nodo *nodo;
	nodo = malloc(sizeof(t_nodo)); // memria sizeof t_nodo
	if (!nodo)
	{
		return ;
	}
	
	nodo->anterior_nodo = NULL;
	nodo->siguiente_nodo = NULL;
	nodo->index = NULL;
	nodo->valor = valor_main;
	
	if (pila->cantidad_elementos == 0)
	{
		pila->primer_elemento = nodo;
		pila->ultimo_elemento = nodo;
	}
	else
	{
		// falta que el anterior nodo apunte al siguiente
		pila->ultimo_elemento->siguiente_nodo = nodo;
		nodo->anterior_nodo = pila->ultimo_elemento;
		
	}
	pila->ultimo_elemento = nodo;
	pila->cantidad_elementos++;
}

void ft_eliminar_nodo(t_pila *pila, t_nodo *nodo)
{
	if (pila->cantidad_elementos == 1)
	{
		pila->primer_elemento = NULL;
		pila->ultimo_elemento = NULL;
	}
	else if (pila->primer_elemento == nodo)
	{
		nodo->siguiente_nodo->anterior_nodo = NULL;
		pila->primer_elemento = nodo->siguiente_nodo;
	}else if (pila->ultimo_elemento == nodo)
	{
		nodo->anterior_nodo->siguiente_nodo = NULL;
		pila->ultimo_elemento = nodo->anterior_nodo;
	}else
	{
		nodo->anterior_nodo->siguiente_nodo = nodo->siguiente_nodo;
		nodo->siguiente_nodo->anterior_nodo = nodo->anterior_nodo;
	}
	pila->cantidad_elementos--;
	free(nodo);
}

t_nodo *ft_cortar_nodo_inicio(t_pila *pila) // restar el contador!!
{
	t_nodo *nodo_cortado;
	t_nodo *segundo_nodo;
	if (pila->cantidad_elementos == 0)
		return NULL;
	nodo_cortado = pila->primer_elemento;
	segundo_nodo = nodo_cortado->siguiente_nodo;
	if (pila->cantidad_elementos <= 1)
	{
		pila->primer_elemento = NULL;
		pila->ultimo_elemento = NULL;
		pila->cantidad_elementos = 0; // no lo dio la ia
		return nodo_cortado;
	}
	

	segundo_nodo->anterior_nodo = NULL;
	nodo_cortado->siguiente_nodo = NULL;
	nodo_cortado ->anterior_nodo = NULL;
	pila->primer_elemento = segundo_nodo;
	pila->cantidad_elementos--;
	return nodo_cortado;
}

void ft_unir_nodo_inicio(t_pila *pila, t_nodo *nodo_nuevo) // nos falta añadir casos
{
	t_nodo *nodo_antiguo;

	nodo_antiguo = NULL;
	if (pila->cantidad_elementos == 0)
	{
		
		nodo_nuevo->siguiente_nodo = NULL;
		nodo_nuevo->anterior_nodo = NULL;
		pila->primer_elemento = nodo_nuevo;
		pila->ultimo_elemento = nodo_nuevo;
		pila->cantidad_elementos++;
		return ;
	}else
	{
		nodo_antiguo = pila->primer_elemento;
		nodo_nuevo->siguiente_nodo = nodo_antiguo;
		nodo_antiguo->anterior_nodo = nodo_nuevo;
		pila->primer_elemento = nodo_nuevo;
		pila->cantidad_elementos++;
	}

}