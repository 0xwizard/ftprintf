/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:45:54 by hsari             #+#    #+#             */
/*   Updated: 2025/06/23 19:52:14 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_typecheck(const char p, va_list ap)
{
	int	i;

	i = 0;
	if (p == 'c')
		i += ft_putchar(va_arg(ap, int));
	if (p == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (p == 'p')
		i +=
	return (i);
}

int	ft_printf(const char *p, ...)
{
	va_list	ap;

	va_start(ap, p);
	while (p)
		if (p == '%')
			ft_typecheck(p + 1, ap);
		else
			ft_putchar(p);
}
