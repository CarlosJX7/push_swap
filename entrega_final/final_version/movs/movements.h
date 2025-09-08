/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:12:28 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:30 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

#include "../node_stack/node_stack.h"
#include "../node_stack/stack_management.h"
#include "../node_stack/node_managment.h"
void	ft_push_a(t_stack *pilaA, t_stack *pilaB);
void	ft_push_b(t_stack *pilaA, t_stack *pilaB);
void	ft_rotate_rev_a(t_stack *pila);
void	ft_rotate_rev_b(t_stack *pila);
void	ft_rotate_rev_r(t_stack *pilaA, t_stack *pilaB);
void	ft_rotate_b(t_stack *pila);
void	ft_rotate_a(t_stack *pila);
void	ft_rotate_r(t_stack *pila_A, t_stack *pila_B);
void	ft_do_sa(t_stack *pilaA);
void	ft_do_sb(t_stack *pilaA);
void	ft_do_ss(t_stack *pilaA, t_stack *pilaB);

#endif
