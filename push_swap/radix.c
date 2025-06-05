#include "nodes.h"
#include "movements.h"
#include "ps_utils.h"
#include <stdio.h>
int rotaciones(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n >> 1;
		i++;
	}
	return i;
	
}
void ft_fill_a(t_pila *pilaA, t_pila *pilaB)
{
    while (pilaB->cantidad_elementos > 0)
    {
        ft_push(pilaB, pilaA);
    }
    
}

void ft_radix(t_pila *pilaA, t_pila *pilaB)
{
    t_nodo *node;
    int comp;
    int rotacion;
    int mask;

    
    comp = 0x01;
    
    mask = 0;
    while (mask < rotaciones(pilaA->cantidad_elementos))
    {
        printf("Estamos en la rotacion numero %d\n", mask);
        rotacion = pilaA->cantidad_elementos;
        while (rotacion > 0)
        {
            printf("Estamos dentro del segundo bucle rotacion = %d: ", rotacion);
            
            node = pilaA->primer_elemento;
            if ((node->index & comp) == 0)
            {
                printf("& = %d  || mov: %d -> B\n", node->index & comp, node->index);
                node = node->siguiente_nodo; //al hacer push puede que no se actualice
                ft_push(pilaA, pilaB);
            }else
            {
                /* code */
            ft_rotate(pilaA);
                //node = node->siguiente_nodo;
            }
            
            //printf("Apuntamos a index: %d\n", node->index);
            rotacion--;
        }
        ft_fill_a(pilaA, pilaB);
        comp = comp<<1;
        mask++;
        /* code */
    }    
    

    
    printf("fin radix\n");
}
