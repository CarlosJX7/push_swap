#	ifndef NODES_H
# define NODES_H

# include <stdlib.h>

typedef struct s_nodo
{
    int valor;
    struct s_nodo *siguiente_nodo;
    struct s_nodo *anterior_nodo;
    int index;
}t_nodo;

typedef struct s_pila
{
    t_nodo *primer_elemento;
    t_nodo *ultimo_elemento;
    int cantidad_elementos;
}t_pila;


void ft_agregar_nodo(t_pila *pila, int valor_main);
void ft_eliminar_nodo(t_pila *pila, t_nodo *nodo);
t_nodo *ft_cortar_nodo_inicio(t_pila *pila);
void ft_unir_nodo_inicio(t_pila *pila, t_nodo *nodo_nuevo);
void ft_vaciar_pila(t_pila *pila);
int *ft_pila_to_array(t_pila *pila);

//ojo a los casos especiales

#endif