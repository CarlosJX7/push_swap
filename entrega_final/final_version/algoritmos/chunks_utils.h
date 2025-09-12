#ifndef CHUNKS_UTILS_H
# define CHUNKS_UTILS_H

# include "../node_stack/node_stack.h"
# include "../movs/movements.h"
 int	ft_stack_size(t_stack *s);
int	ft_isqrt(int n);
int	ft_pos_of_index(t_stack *s, int target);
int	ft_min_index_in_stack(t_stack *s);
int	ft_pos_of_max_in_b(t_stack *b, int *out_max_idx);
void	ft_bring_pos_to_top_a(t_stack *a, int pos);
void	ft_bring_pos_to_top_b(t_stack *b, int pos);

#endif