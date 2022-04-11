/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:12:50 by zessadqu          #+#    #+#             */
/*   Updated: 2021/12/27 04:33:51 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		hexa_len_1(unsigned long nbr);

char	*to_hexa(unsigned long nbr);

void	ft_hexa_ptr(void *ptr, int *x)
{
	char	*str;

	ft_putstr("0x", x);
	if (!ptr)
		ft_putchar('0', x);
	str = to_hexa((unsigned long)ptr);
	ft_putstr(str, x);
	free(str);
}

int	hexa_len_1(unsigned long nbr)
{
	int	x;

	x = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		x++;
	}
	return (x);
}

char	*to_hexa(unsigned long nbr)
{
	int		i;
	int		count;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	count = hexa_len_1(nbr);
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count] = 0;
	i = count - 1;
	while (nbr >= 16)
	{
		str[i] = hex[nbr % 16];
		i--;
		nbr = nbr / 16;
	}
	str[i] = hex[nbr];
	return (str);
}
