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

unsigned long ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int ft_base(unsigned long x, char *base)
{
	int count; 

	count = 0;
    if (x >= ft_strlen(base))
        count += ft_base(x / ft_strlen(base), base);
	count += ft_putchar(base[x % ft_strlen(base)]);
	return (count);
}
int ft_putnbr(long x)
{
	if (x == -2147483648) 
		return (ft_putstr("-2147483648"));
	else if (x < 0) 
		return (ft_putchar('-') + ft_putnbr(-x));
	else if (x <= 9)
		return (ft_putchar(x + ('0')));
	else 
		return (ft_putnbr(x / 10) + ft_putnbr(x % 10));
}
/* 
int	ft_putnbrbase(long long x, char *base)
{
	int	count;

	count = 0;
	if (x == 0)
		return (count += ft_putchar(base[0]));
	if (x < 0)
		x *= -1;
	count += ft_base(x, base);
	return (count);
}*/
/*
#include <stdio.h>

int	main(void)
{
	ft_putnbr(-42);
	//ft_putnbrbase(-1, "0123456789");
}
*/


