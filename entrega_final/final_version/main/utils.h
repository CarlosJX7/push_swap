/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:12:14 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:16 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../node_stack/node_stack.h"
# include "main_utils.h"

int		ft_atoi(char *s);
void	ft_index_ordenado(t_stack *pila, int *array);
int		*ft_ordenar_array(int *array, int n);
int		ft_strlen(const char *str);
int		ft_isspace(char c);

#endif
