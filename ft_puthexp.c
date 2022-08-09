/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:45:44 by kkongim           #+#    #+#             */
/*   Updated: 2022/07/16 17:28:51 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexlong(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		if (n > 9)
			i += ft_putchar(n + 87);
		else
			i += ft_putchar(n + 48);
	}
	else if (n >= 16)
	{
		i += puthexlong(n / 16);
		i += puthexlong(n % 16);
	}
	return (i);
}

int	ft_puthexp(void *p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += puthexlong((unsigned long)p);
	return (i);
}
