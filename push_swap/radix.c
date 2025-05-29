#include "nodes.h"
#include "movements.h"
#include "ps_utils.h"

void ft_radix(t_pila *pilaA, t_pila *pilaB)
{
    t_nodo *node;

    node = pilaA->primer_elemento;

    while (node != NULL)
    {
        if (node->index & (0X01 == 1))
        {
            ft_push(pilaA, pilaB);
        }
        node = node->siguiente_nodo;
    }
}