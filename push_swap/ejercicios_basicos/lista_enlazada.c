#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    char *contenido;
    struct s_nodo *siguiente;
    struct s_nodo *anterior;
} t_nodo;

void ft_imprimir_nodo(t_nodo *nodo)
{
    printf("Contenido del nodo: %s", nodo->contenido);
    if (nodo->siguiente)
        printf("Hay nodo siguiente\n");
    else
        printf("No hay nodo siguiente\n");
    if (nodo->anterior)
        printf("Hay nodo anterior\n");
    else
        printf("No hay nodo anterior\n");
}

int main(int argc, char const *argv[])
{
    t_nodo *nodo1;
    t_nodo *nodo2;
    nodo1 = malloc(sizeof(t_nodo));
    nodo1->contenido = "Primero\n";
    nodo1->siguiente = NULL;
    nodo1->anterior = NULL;

    nodo2 = malloc(sizeof(t_nodo));
    nodo2->contenido = "Segundo\n";
    nodo2->siguiente = NULL;
    nodo2->anterior = NULL;

    ft_imprimir_nodo(nodo1);
    ft_imprimir_nodo(nodo2);

    printf("\n--Conectando nodos--\n\n");

    nodo1->siguiente = nodo2;
    nodo2->anterior = nodo1;
    ft_imprimir_nodo(nodo1);
    ft_imprimir_nodo(nodo2);
    return 0;
}
