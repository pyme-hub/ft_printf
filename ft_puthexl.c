/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:53:28 by kkongim           #+#    #+#             */
/*   Updated: 2022/07/16 17:48:40 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexl(unsigned int n)
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
		i += ft_puthexl(n / 16);
		i += ft_puthexl(n % 16);
	}
	return (i);
}
