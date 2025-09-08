/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:14:26 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:14:28 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <stdlib.h>
#include "../main/utils.h"
#include "../node_stack/node_managment.h"
#include "../node_stack/node_stack.h"

int ft_is_duplicate(int *array,int size, int n);
int	*ft_get_array(int n, char *argv[]);
void	ft_fill_stack(t_stack *pila, int *array, int n);
int	ft_count_tokens(char **tokens);
void ft_free_tokens(char **tokens);

#endif
