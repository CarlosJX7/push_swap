#include "nodes.h"
#include "movements.h"
#include "ps_utils.h"
#include <stdio.h>
void ft_radix(t_pila *pilaA, t_pila *pilaB)
{
    t_nodo *node;
    int comp;

    comp = 0x01;
    node = pilaA->primer_elemento;
    printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (node != NULL)
    {
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
        if ((node->index & comp) == 1)
        {
            printf("& = %d  || mov: %d -> B\n", node->index & comp, node->index);
            ft_push(pilaA, pilaB);
        }
        node = node->siguiente_nodo;
    }
    printf("fin radix\n");
}