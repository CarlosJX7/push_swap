#include "movements.h"
#include "node.h"
#include "utils.h"

t_stack *ft_iniciar_pila(t_stack *pila)
{
	pila = malloc(sizeof(t_stack));
	if (!pila)
		return NULL;
	pila->primer_elemento = NULL;
	pila->ultimo_elemento = NULL;
	pila->cantidad_elementos = 0;
	return pila;
}

int	main(int argc, char *argv[])
{
	t_stack	*pila_A;
	t_stack	*pila_B;
	int i;
	int *array_ordenado;

	if (argc < 2)
		return 0;
	pila_A = ft_iniciar_pila(pila_A);
	pila_B = ft_iniciar_pila(pila_B);

	i = 0;
	while (argv[i])
	{
		ft_nodo_a_pila(ft_crear_nodo(ft_atoi(argv[i])), pila_A);
		i++;
	}
	array_ordenado = ft_ordenar_array(ft_pila_to_array(pila_A), pila_A->cantidad_elementos);
	ft_pila_indices(pila_A, array_ordenado);
	
	ft_radix(pila_A, pila_B);
	ft_pila_free(pila_A);
	ft_pila_free(pila_B);
	free(array_ordenado);
	return 0;
}
