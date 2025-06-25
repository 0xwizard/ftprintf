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
	int	i;

	i = 0;
	if (p == 'c')
		i += ft_putchar(va_arg(ap, int));
	if (p == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (p == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbrbase(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	if (p == 'x')
		i += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789abcdef");
	if (p == 'X')
		i += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (p == 'i' || p == 'd')
		i += ft_putnbrbase(va_arg(ap, int), "0123456789");
	if (p == 'u')
		i += ft_putnbrbase(va_arg(ap, unsigned int), "0123456789");
	if (p == '%')
		i += ft_putchar('%');
	return (i);
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
