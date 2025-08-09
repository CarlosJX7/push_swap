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
