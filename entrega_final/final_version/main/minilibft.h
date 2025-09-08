#ifndef MINILIBFT_H
# define MINILIBFT_H

int	ft_strlen(const char *str);
static char	**ft_malloc_error(char **tab);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
static void	ft_zerovalues(unsigned int *a, unsigned int *b);
char	**ft_split(char const *s, char c);

#endif