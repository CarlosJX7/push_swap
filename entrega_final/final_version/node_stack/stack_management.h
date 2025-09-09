/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:46 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:13:47 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MANAGEMENT_H
# define STACK_MANAGEMENT_H

# include "node_stack.h"

t_stack	*ft_pila_ini(void);
int		*ft_stack_to_array(t_stack *pila);
void	ft_pila_free(t_stack *pila);
int		ft_array_ordenado_check(int *array, int n);
int		*ft_pila_to_array(t_stack *pila);

#endif
