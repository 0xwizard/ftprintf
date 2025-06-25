/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:59:20 by hsari             #+#    #+#             */
/*   Updated: 2025/06/24 22:28:10 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase(long long x, char *base)
{
	int	len;
	int	i;
	int	count;
	char	res[19];

	len = 0;
	count = 0;
	while (base[len])
		len++;
	if (x < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbrbase(-x, base);
		return (count);
	}
	i = 0;
	while (x)
	{
		res[i++] = base[x % len];
		x /= len;
	}
	while (--i >= 0)
		count += ft_putchar(res[i]);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	// ft_putnbr(444);
	printf("%d", ft_putnbr(2147483647));
}*/

