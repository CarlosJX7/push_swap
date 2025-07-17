#include "ps_utils.h"
#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int	sign;
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


int	ft_buscar_en_array(int *array, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_ordenar_array(int *array, int cantidad)
{
	int	*array_ordenado;
	int	i;
	int	min;
	int	min_idx;
	int	ordenados;

	array_ordenado = (int *)malloc(sizeof(int) * cantidad);
	if (!array_ordenado)
		return (NULL);
	ordenados = 0;
	while (ordenados < cantidad)
	{
		min = 2147483647; // INT_MAX
		min_idx = -1;
		i = 0;
		while (i < cantidad)
		{
			if (!ft_buscar_en_array(array_ordenado, array[i], ordenados)
				&& array[i] < min)
			{
				min = array[i];
				min_idx = i;
			}
			i++;
		}
		if (min_idx != -1)
		{
			array_ordenado[ordenados] = array[min_idx];
			ordenados++;
		}
	}
	return (array_ordenado);
}
