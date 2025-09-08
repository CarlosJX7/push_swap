#ifndef UTILS_H
# define UTILS_H
# include "node.h"

int		ft_atoi(char *s);
void	ft_index_ordenado(t_stack *pila, int *array);
int		*ft_ordenar_array(int *array, int n);
int		ft_strlen(const char *str);
int	ft_isspace(char c);
#endif