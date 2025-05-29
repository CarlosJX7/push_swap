#include "nodes.h"
#include "movements.h"
#include "ps_utils.h"
#include <stdio.h>
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
    

    rotacion = pilaA->cantidad_elementos;

    comp = 0x01;
    //printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->siguiente_nodo->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (rotacion > 0)
    {

        node = pilaA->primer_elemento;
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
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


    rotacion = pilaA->cantidad_elementos;

    comp = 0x02;
    //printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->siguiente_nodo->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (rotacion > 0)
    {

        node = pilaA->primer_elemento;
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
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


    rotacion = pilaA->cantidad_elementos;

    comp = 0x03;
    //printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->siguiente_nodo->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (rotacion > 0)
    {

        node = pilaA->primer_elemento;
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
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


    rotacion = pilaA->cantidad_elementos;

    comp = 0x04;
    //printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->siguiente_nodo->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (rotacion > 0)
    {

        node = pilaA->primer_elemento;
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
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



    rotacion = pilaA->cantidad_elementos;

    comp = 0x10;
    //printf("P index = %d\n", node->index);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->valor);
    printf("PRIMER index = %d\n", pilaA->primer_elemento->siguiente_nodo->valor);
    printf("LAST index = %d\n", pilaA->ultimo_elemento->valor);
    while (rotacion > 0)
    {

        node = pilaA->primer_elemento;
        printf("e\n");
        printf("indexxxxx = %d\n", node->index);
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



    
    printf("fin radix\n");
}
