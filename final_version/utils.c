#include "node.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	long	nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] != '\0') && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * nbr);
}

int *ft_ordenar_array(int *array, int n)
{
	int	i;
	int	j;
	int aux;
	i = 0;
	j = n;
	while (j > 0)
	{
		while (i < j -1)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
			}
			i++;
		}
		i = 0;
		j--;
	}
	return array;
}

int	ft_index(int n, int *array, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (array[i] == n)
		{
			return i;
		}
		i++;
	}
	return 0;
}

void	ft_index_ordenado(t_stack *pila, int *array)
{
	t_node *nodo;
	int index;

	nodo = pila->primer_elemento;
	while (nodo)
	{
		index = ft_index(nodo->valor, array, pila->cantidad_elementos);
		nodo->index = index;
		nodo = nodo->siguiente_nodo;
	}
	
}
