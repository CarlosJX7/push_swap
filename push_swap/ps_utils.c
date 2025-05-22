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

int *ft_ordenar_array(int * array, t_pila *pila)
{
	int *array_ordenado;
	t_nodo *nodo_posicion;
	int i;
	array_ordenado = malloc(sizeof(int) * pila->cantidad_elementos);
	int valor_menor;
	valor_menor = nodo_posicion->valor;
	while (nodo_posicion->siguiente_nodo != NULL)
	{
		if (nodo_posicion->valor < valor_menor)
		{
			valor_menor = nodo_posicion->valor;
		}
	}
	
	array_ordenado[i] = valor_menor;
	nodo_posicion = nodo_posicion->siguiente_nodo;

	return 0;
}
