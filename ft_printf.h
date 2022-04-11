/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:12:47 by zessadqu          #+#    #+#             */
/*   Updated: 2021/12/26 19:12:55 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *x);
void	ft_putstr(char *str, int *x);
void	ft_putnbr(long int n, int *x);
void	ft_putnbr_unsigned(unsigned int n, int *x);
int		ft_strlen(const char *str);
void	ft_hexa(unsigned long hex, char c, int *x);
void	ft_hexa_ptr(void *ptr, int *x);
#endif
