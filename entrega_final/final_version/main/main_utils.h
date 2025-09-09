/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:31 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:11:36 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "../node_stack/node_stack.h"

void	ft_error_check(char **argv, int argc);
void	ft_print_error(void);
int		ft_algoritmos(int n, t_stack *pilaA, t_stack *pilaB);

#endif
