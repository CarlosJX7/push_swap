/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:56 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:11:58 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"
#include "main_utils.h"
#include "utils.h"
#include "../node_stack/node_stack.h"
#include "../parsing/parsing.h"
#include "../parsing/get_string.h"
#include "../node_stack/stack_management.h"
#include "../node_stack/node_managment.h"
#include "../algoritmos/algoritmos.h"
#include "../algoritmos/radix.h"

int	*ft_contruir_array(char **tokens, int *array)
{
	int	i;

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
	char	**tokens;
	int		*array;

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
	return (ft_contruir_array(tokens, array));
}

static int	*ft_parse_args(int argc, char **argv, int *size)
{
	int	*array;
	int	i;

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

static void	ft_process(int *array, int size)
{
	t_stack	*pila_a;
	t_stack	*pila_b;
	int		*aux;

	pila_a = ft_pila_ini();
	pila_b = ft_pila_ini();
	if (!pila_a || !pila_b)
	{
		free(array);
		ft_print_error();
	}
	ft_fill_stack(pila_a, array, size);
	free(array);
	if (ft_pila_to_array(pila_a) == NULL)
	{
		ft_pilas_free(pila_a, pila_b);
		return ;
	}
	aux = ft_pila_to_array(pila_a);
	aux = ft_ordenar_array(aux, pila_a->cantidad_elementos);
	ft_index_ordenado(pila_a, aux);
	free(aux);
	if (!ft_algoritmos(size + 1, pila_a, pila_b))
		ft_radix(pila_a, pila_b);
	ft_pilas_free(pila_a, pila_b);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	size;
	int	k;

	k = 0;
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
	ft_process(array, size);
	return (0);
}
