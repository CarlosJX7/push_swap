// Headers according to your Makefile
#include <stddef.h> // size_t

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_next_number(const char *str, size_t *pos, const char **start, size_t *len)
{
	size_t	i;
	int		has_digit;

	if (!str || !pos || !start || !len)
		return (0);
	i = *pos;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	*start = &str[i];
	if (str[i] == '+' || str[i] == '-')
		i++;
	has_digit = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		has_digit = 1;
		i++;
	}
	*len = (size_t)(&str[i] - *start);
	*pos = i;
	return (has_digit);
}
