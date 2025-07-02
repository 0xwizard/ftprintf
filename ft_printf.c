/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:45:54 by hsari             #+#    #+#             */
/*   Updated: 2025/06/25 21:38:21 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_typecheck(const char p, va_list ap)
{
	if (p == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (p == 's')
		return  (ft_putstr(va_arg(ap, char *)));
	else if (p == 'p')
		return (ft_putp(va_arg(ap, void *)));
	else if (p == 'x')
		return (ft_putx(va_arg(ap, unsigned int), p));
	else if (p == 'X')
		return (ft_putx(va_arg(ap, unsigned int), p));
	else if (p == 'i' || p == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (p == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (p == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *p, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, p);
	count = 0;
	while (*p)
	{
		if (*p == '%')
			count += ft_typecheck(*(++p), ap);
		else
			count += ft_putchar(*p);
		p++;
	}
	return (count);
}
