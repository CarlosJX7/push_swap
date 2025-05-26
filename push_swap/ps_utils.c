#include "ps_utils.h"


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

int ft_buscar_en_array(int *array, int n, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == n)
		{
			return 1;
		}
	}
	return 0;
}

int *ft_ordenar_array(int *array, t_pila *pila)
{
	int posicion;
	int *array_ordenado;
	int flecha;
	int n;

	flecha = 0;
	posicion = 0;
	array_ordenado = malloc(sizeof(int)*pila->cantidad_elementos);
	if (!array_ordenado)
		return 0;
	while (flecha < pila->cantidad_elementos)
	{
		posicion = flecha;
		n = array[flecha];
		while (posicion < pila->cantidad_elementos)
		{
			if (array_ordenado[posicion] < n && ft_buscar_en_array(array ,array_ordenado[posicion], pila->cantidad_elementos))
			{
				n = array_ordenado[posicion];
			}
			posicion++; 
		}
		array_ordenado[flecha] = n;
		flecha++;
	}
	
	return array_ordenado;
}

