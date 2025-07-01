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
	void *x; 

	x = 0; 
	if (p == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (p == 's')
		return  (ft_putstr(va_arg(ap, char *)));
	else if (p == 'p')
	{
		x = va_arg(ap, void *);
		if (!x)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_putnbrbase((unsigned long)x, "0123456789abcdef"));
	}
	else if (p == 'x')
		return (ft_putnbrbase(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (p == 'X')
		return (ft_putnbrbase(va_arg(ap, unsigned int), "0123456789ABCDEF"));
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
