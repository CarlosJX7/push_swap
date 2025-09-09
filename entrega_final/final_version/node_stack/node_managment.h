/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_managment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:28 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:13:30 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_MANAGMENT_H
# define NODE_MANAGMENT_H

# include "node_stack.h"
# include "stack_management.h"

t_node	*ft_crear_nodo(int valor);
void	ft_nodo_a_pila(t_node *new_nodo, t_stack *pila);
t_node	*ft_cortar_nodo(t_stack *pila);
void	ft_pilas_free(t_stack *pila_a, t_stack *pila_b);

#endif
