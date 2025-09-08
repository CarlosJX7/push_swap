/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:14:22 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:14:23 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"



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
 int	ft_count_tokens(char **tokens)
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
