#include "push_swap.h"

void ft_print_error(void)
{
			write(2, "Error\n", 6);
			exit(1);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
void ft_error_check(char **argv, int argc)
{
	int	i;
	i = 1;
	if (argc <= 1)
		ft_print_error();
	
	while (argv[i])
	{
		if (!ft_strlen(argv[i]))
			ft_print_error();
		i++;
	}
}

int	ft_algoritmos(int n, t_stack *pilaA, t_stack *pilaB)
{
	if (n == 3)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	if (n == 4)
	{
		ft_tres_elementos(pilaA, pilaB);
		return (1);
	}
	if (n == 5)
	{
		ft_cuatro_elementos(pilaA, pilaB);
		return (1);
	}

	if (n == 6)
	{
		ft_cinco_elementos(pilaA, pilaB);
		return(1);
	}
	
	return 0;
}