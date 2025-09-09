/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:08 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:11:10 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_H
# define RADIX_H

# include "../node_stack/node_stack.h"
# include "../movs/movements.h"

int		ft_cantidad_bits(int n);
void	ft_vaciar_b(t_stack *pilaA, t_stack *pilaB);
void	ft_algoritmo(t_stack *pilaA, t_stack *pilaB, int bit);
void	ft_radix(t_stack *pilaA, t_stack *pilaB);

#endif
