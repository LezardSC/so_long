/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:09:57 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/26 17:31:47 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	search_arg(va_list arg, char c);
int	ispercent_c(int c);
int	ispercent_d_i(int nb);
int	ispercent_u(unsigned int u);
int	ispercent_s(char *s);
int	ispercent_x(unsigned int x);
int	ispercent_capx(unsigned int x);
int	ispercent_p(unsigned long p);

#endif