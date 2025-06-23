/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:59:20 by hsari             #+#    #+#             */
/*   Updated: 2025/06/23 20:59:20 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char numb;
	int count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-nb);
	}
	else if (nb <= 9)
	{
		numb = nb + '0';
		count += ft_putchar(numb);
	}
	else
	{
		count+=ft_putnbr(nb / 10);
		count+=ft_putnbr(nb % 10);
	}
	return (count);
}
#include <stdio.h>

int main(void)
{
	//ft_putnbr(444);
	printf("%d", ft_putnbr(2147483647));
}
