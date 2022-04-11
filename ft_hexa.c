/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:12:30 by zessadqu          #+#    #+#             */
/*   Updated: 2021/12/27 04:27:37 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		hexa_len(unsigned long nbr);

char	*hexa_maj(unsigned long nbr);

char	*hexa_min(unsigned long nbr);

void	ft_hexa(unsigned long hex, char c, int *x)
{
	char	*str;

	if (hex == 0)
		ft_putchar('0', x);
	if (c == 'x')
	{
		str = hexa_min(hex);
		ft_putstr(str, x);
		free(str);
	}
	if (c == 'X')
	{
		str = hexa_maj(hex);
		ft_putstr(str, x);
		free(str);
	}
}

int	hexa_len(unsigned long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

char	*hexa_min(unsigned long nbr)
{
	int		i;
	int		count;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	count = hexa_len(nbr);
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

char	*hexa_maj(unsigned long nbr)
{
	int		i;
	int		count;
	char	*str;
	char	*hex;

	hex = "0123456789ABCDEF";
	count = hexa_len(nbr);
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

/*int main()
{
    unsigned long i = 98984;
    int x = 3;
    char c = 'X';
    ft_hexa(i, c, &x);


}
*/
