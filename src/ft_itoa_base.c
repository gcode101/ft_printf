/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 07:51:37 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/05 13:52:24 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_char(int index)
{
	char	*str;

	str = "0123456789abcdef";
	return (str[index]);
}

static int	get_digits(long long num, int base)
{
	long long	nb;
	int			digits;

	if (num == 0)
		digits = 1;
	else
		digits = 0;
	nb = num;
	while (nb != 0)
	{
		nb /= base;
		digits++;
	}
	return (digits);
}

char	*ft_itoa_base(long long value, int base)
{
	long long	num;
	int			neg;
	int			digits;
	char		*re;

	num = value;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	if (num < 0)
		num *= -1;
	digits = get_digits(num, base);
	if (!(re = malloc(sizeof(char) * digits + neg + 1)))
		return (NULL);
	if (neg)
		re[0] = '-';
	re[digits + neg] = '\0';
	if (!neg)
		digits--;
	while (digits >= neg)
	{
		re[digits--] = get_char(num % base);
		num /= base;
	}
	return (re);
}

