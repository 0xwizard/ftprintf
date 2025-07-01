/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:08:49 by hsari             #+#    #+#             */
/*   Updated: 2025/06/24 22:29:08 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *p);
int ft_strlen(char *base);
int ft_base(unsigned long x, char *base);
int ft_putnbr(long x);
int	ft_putnbrbase(long long x, char *base);

#endif
