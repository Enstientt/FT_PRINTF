/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:13:06 by zessadqu          #+#    #+#             */
/*   Updated: 2021/12/26 19:16:18 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	check_result(va_list args, char c, int *x)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), x);
	if (c == 's')
		ft_putstr(va_arg(args, char *), x);
	if (c == 'p')
		ft_hexa_ptr(va_arg(args, void *), x);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), x);
	if (c == 'u')
		ft_putnbr_unsigned((unsigned)va_arg(args, int), x);
	if (c == 'x' || c == 'X')
		ft_hexa((unsigned int)va_arg(args, int), c, x);
	if (c == '%')
		ft_putchar('%', x);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	args;

	va_start(args, str);
	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && !str[i + 1])
			return (x);
		else if (str[i] == '%')
		{
			i++;
			check_result(args, str[i], &x);
			i++;
		}
		else
			ft_putchar(str[i++], &x);
	}
	va_end(args);
	return (x);
}
