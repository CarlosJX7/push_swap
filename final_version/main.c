#include "push_swap.h"

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

static int	ft_count_tokens(char **tokens)
{
	int i = 0;
	while (tokens[i])
		i++;
	return (i);
}

void ft_free_tokens(char **tokens)
{
	int i;
	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

//auxiliares arriba

int	*ft_contruir_array(char **tokens, int *array)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		array[i] = ft_atoi(tokens[i]);
		if (ft_is_duplicate(array, i, array[i]))
		{
			free(array);
			ft_free_tokens(tokens);
			ft_print_error();
		}
		i++;
	}
	ft_free_tokens(tokens);
	return (array);

}

static int	*ft_parse_single_arg(char *arg, int *size)
{
	char **tokens;
	int *array;

	if (!arg)
		ft_print_error();
	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_print_error();
	*size = ft_count_tokens(tokens);
	array = malloc(*size * sizeof(int));
	if (!array)
	{
		ft_free_tokens(tokens);
		ft_print_error();
	}

	return ft_contruir_array(tokens, array);
	//detener aqui

}

static int	*ft_parse_args(int argc, char **argv, int *size)
{
	int *array;
	int i;

	*size = argc - 1;
	array = malloc(*size * sizeof(int));
	if (!array)
		ft_print_error();
	i = 0;
	while (i < *size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		if (ft_is_duplicate(array, i, array[i]))
		{
			free(array);
			ft_print_error();
		}
		i++;
	}
	return (array);
}

static void	ft_process(int *array, int size, char **env)
{
	t_stack *pila_a = ft_pila_ini();
	t_stack *pila_b = ft_pila_ini();
	int *aux;
	(void)env;


	if (!pila_a || !pila_b)
	{
		free(array);
		ft_print_error();
	}
	ft_fill_stack(pila_a, array, size);
	free(array);
	if (ft_pila_to_array(pila_a) == NULL)
	{
		ft_pila_free(pila_a);
		ft_pila_free(pila_b);
		return ;
	}
	aux = ft_pila_to_array(pila_a);
	aux = ft_ordenar_array(aux, pila_a->cantidad_elementos);
	ft_index_ordenado(pila_a, aux);
	free(aux);
	if (!ft_algoritmos(size + 1, pila_a, pila_b))
		ft_radix(pila_a, pila_b);
	ft_pila_free(pila_a);
	ft_pila_free(pila_b);
}

int	main(int argc, char **argv, char **env)
{
	int *array;
	int size;
	int k = 0;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		while (argv[1][k] && ft_isspace(argv[1][k]))
			k++;
		if (argv[1][k] == '\0')
    		ft_print_error();
		array = ft_parse_single_arg(argv[1], &size);
	}
	else
		array = ft_parse_args(argc, argv, &size);
	ft_process(array, size, env);
	return (0);
}
