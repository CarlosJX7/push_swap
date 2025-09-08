/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:48 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:11:50 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include "../parsing/parsing.h"
#include "../parsing/get_string.h"
int	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);

#endif
