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

#ifndef NODE_MANAGEMENT_H
# define NODE_MANAGEMENT_H

#include "node_stack.h"

t_node	*ft_crear_nodo(int valor);
void	ft_nodo_a_pila(t_node *new_nodo, t_stack *pila);
t_node	*ft_cortar_nodo(t_stack *pila);

#endif
