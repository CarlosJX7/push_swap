#include "push_swap.h"
#include <stdio.h>


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

static void	ft_zerovalues(unsigned int *a, unsigned int *b)
{
	*a = 0;
	*b = 0;
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!tab)
		return (NULL);
	next_str = (char *)s;
	ft_zerovalues(&next_str_len, &i);
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!tab)
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

//------------------------

void	ft_imprimir_pila(t_stack *pila)
{
	t_node	*nodo;

	if (pila->cantidad_elementos == 0)
		return ;
	nodo = pila->primer_elemento;
	while (nodo)
	{
		printf("valor >%d<, indice >%d<\n", nodo->valor, nodo->index);
		nodo = nodo->siguiente_nodo;
	}
}

void	ft_imprimir_pilas(t_stack *pilaA, t_stack *pilaB)
{
	printf("Imprimimos pila A (n = %d)\n", pilaA->cantidad_elementos);
	ft_imprimir_pila(pilaA);
	printf("Imprimimos pila B (n = %d)\n", pilaB->cantidad_elementos);
	ft_imprimir_pila(pilaB);
	printf("\n--------------------------\n\n");
}

void	ft_imprimir_array(int *array, int n)
{
	int	i;

	i = 0;
	printf("Imprimiendo array\n");
	while (i < n)
	{
		printf("array: %d\n", array[i]);
		i++;
	}
}
// inicio de codigo 
int ft_is_duplicate(int *array,int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == array[i])
		{
			return 1;
		}
		i++;
	}
	return (0);
}

int	*ft_get_array(int n, char *argv[])
{
	int	*array;
	int	i;
	int num;

	i = 0;
	array = malloc(n * sizeof(int));
	if (!array)
		return (NULL);
	while (i < n)
	{
		num = ft_atoi(argv[i + 1]);
		if (ft_is_duplicate(array, i, num))
		{
			free(array);
			return NULL;
		}
		array[i] = num;
		i++;
	}
	return (array);
}

void	ft_fill_stack(t_stack *pila, int *array, int n)
{
	t_node	*nodo;

	n = n - 1;
	while (n >= 0)
	{
		nodo = ft_crear_nodo(array[n]);
		ft_nodo_a_pila(nodo, pila);
		n--;
	}
	//free(array);
}

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	int		*array;
	int		size;
	int		i;
	int		num;

	if (argc < 2)
		return (0); // Salida silenciosa si no hay argumentos

	if (argc == 2)
	{
    int k = 0;
    while (argv[1][k] && ft_isspace(argv[1][k]))
        k++;
    if (argv[1][k] == '\0')
        ft_print_error();

    tokens = ft_split(argv[1], ' ');
    if (!tokens)
        ft_print_error();

		// Contar tokens
		size = 0;
		while (tokens[size])
			size++;

		array = malloc(size * sizeof(int));
		if (!array)
		{
			i = 0;
			while (tokens[i])
				free(tokens[i++]);
			free(tokens);
			ft_print_error();
		}

		i = 0;
		while (tokens[i])
		{
			num = ft_atoi(tokens[i]);
			// Comprobar duplicados
			if (ft_is_duplicate(array, i, num))
			{
				// Liberar memoria antes de error
				free(array);
				int j = 0;
				while (tokens[j])
					free(tokens[j++]);
				free(tokens);
				ft_print_error();
			}
			array[i] = num;
			i++;
		}
		// Liberar todos los tokens tras usarlos
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
	else
	{
		size = argc - 1;
		array = malloc(size * sizeof(int));
		if (!array)
			ft_print_error();

		i = 0;
		while (i < size)
		{
			num = ft_atoi(argv[i + 1]);
			if (ft_is_duplicate(array, i, num))
			{
				free(array);
				ft_print_error();
			}
			array[i] = num;
			i++;
		}
	}

	// Inicializa pilas
	t_stack *pila_a = ft_pila_ini();
	t_stack *pila_b = ft_pila_ini();
	if (!pila_a || !pila_b)
	{
		free(array);
		ft_print_error();
	}

	ft_fill_stack(pila_a, array, size);
	free(array);

	// Si ya está ordenado
	if (ft_pila_to_array(pila_a) == NULL)
	{
		ft_pila_free(pila_a);
		ft_pila_free(pila_b);
		return (0);
	}

	array = ft_pila_to_array(pila_a);
	array = ft_ordenar_array(array, pila_a->cantidad_elementos);
	ft_index_ordenado(pila_a, array);
	free(array);

	if (!ft_algoritmos(size + 1, pila_a, pila_b))
		ft_radix(pila_a, pila_b);

	ft_pila_free(pila_a);
	ft_pila_free(pila_b);
	return (0);
}
