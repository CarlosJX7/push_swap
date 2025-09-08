/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:33 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:13:34 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				valor;
	int				index;
	struct s_node	*siguiente_nodo;
	struct s_node	*anterior_nodo;
}	t_node;

typedef struct s_stack
{
	t_node	*primer_elemento;
	t_node	*ultimo_elemento;
	int		cantidad_elementos;
}	t_stack;

#endif
