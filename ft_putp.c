/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsari <hsari@student.42istanbul.com.t      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:42:59 by hsari             #+#    #+#             */
/*   Updated: 2025/07/03 17:42:59 by hsari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putp(void *p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x")
		+ ft_putnbrbase((unsigned long)p, "0123456789abcdef"));
}
