#	ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
/*
typedef struct s_nodo
{
    int valor;
    struct nodo *siguiente_nodo;
    struct nodo *anterior_nodo;
}t_nodo;

typedef struct s_pila
{
    struct nodo *primer_elemento;
    struct nodo *ultimo_elemento;
    int cantidad_elementos;
}t_pila;

*/
typedef struct s_nodo
{
    int valor;
    struct s_nodo *siguiente_nodo;
    struct s_nodo *anterior_nodo;
}t_nodo;

typedef struct s_pila
{
    t_nodo *primer_elemento;
   
    t_nodo *ultimo_elemento;
    int cantidad_elementos;
}t_pila;

int		ft_atoi(const char *str);
void ft_agregar_nodo(t_pila *pila, int valor_main);
void ft_eliminar_nodo(t_pila *pila, t_nodo *nodo);
void ft_vaciar_pila(t_pila *pila);
int *ft_pila_to_array(t_pila *pila);
void ft_rotate(t_pila *pila);
void ft_rotate_inverso(t_pila *pila);
t_nodo *ft_cortar_nodo_inicio(t_pila *pila);
void ft_unir_nodo_inicio(t_pila *pila, t_nodo *nodo_nuevo);
void ft_push(t_pila *pila_origen, t_pila *pila_destino);
void ft_swap(t_pila *pila);
//ojo a los casos especiales
void menu_interactivo_flechas(t_pila *pilaA, t_pila *pilaB);

#endif