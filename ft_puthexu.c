/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:38:29 by kkongim           #+#    #+#             */
/*   Updated: 2022/07/16 17:48:58 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexu(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		if (n > 9)
			i += ft_putchar(n + 55);
		else
			i += ft_putchar(n + 48);
	}
	else if (n >= 16)
	{
		i += ft_puthexu(n / 16);
		i += ft_puthexu(n % 16);
	}
	return (i);
}
