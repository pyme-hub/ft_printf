/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkongim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:52:40 by kkongim           #+#    #+#             */
/*   Updated: 2022/07/16 17:47:54 by kkongim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	toprint(va_list *ap, const char c);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		length;

	va_start(ap, str);
	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			length = length + toprint(&ap, str[i]);
			i++;
		}
		else
		{
			length = length + ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (length);
}

int	toprint(va_list *ap, const char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar(va_arg(*ap, int));
	if (c == 's')
		ret += ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
		ret += ft_puthexp(va_arg(*ap, void *));
	if (c == 'd')
		ret += ft_putnbr(va_arg(*ap, int));
	if (c == 'i')
		ret += ft_putnbr(va_arg(*ap, int));
	if (c == 'u')
		ret += ft_putunsigned(va_arg(*ap, unsigned int));
	if (c == 'x')
		ret += ft_puthexl(va_arg(*ap, unsigned int));
	if (c == 'X')
		ret += ft_puthexu(va_arg(*ap, unsigned int));
	if (c == '%')
		ret += ft_putchar('%');
	return (ret);
}
