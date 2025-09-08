#ifndef NODE_H
# define NODE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				valor;
	int				index;
	struct s_node	*siguiente_nodo;
	struct s_node	*anterior_nodo;
}	t_node;

typedef struct s_stack
{
	t_node	*primer_elemento;
	t_node	*ultimo_elemento;
	int		cantidad_elementos;
}	t_stack;

t_node	*ft_crear_nodo(int valor);
void	ft_nodo_a_pila(t_node *new_nodo, t_stack *pila);
t_node	*ft_cortar_nodo(t_stack *pila);

#endif
