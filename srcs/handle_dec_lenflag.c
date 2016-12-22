/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec_lenflag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:25:38 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 10:25:44 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_char(int index)
{
	char	*str;

	str = "0123456789abcdef";
	return (str[index]);
}

static int	get_digits(char num, int base)
{
	char		nb;
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

static char	*ft_itoa_char(char value, int base)
{
	char		num;
	int			neg;
	int			digits;
	char		*re;

	if (value == -128)
		return ("-128");
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

char	*handle_dec_lenflag(char *len_flag, va_list args)
{

	if (len_flag && ft_strcmp(len_flag, "l") == 0)
		return (ft_itoa_base(va_arg(args, long), 10));
	else if (len_flag && ft_strcmp(len_flag, "ll") == 0)
		return (ft_itoa_base(va_arg(args, long long), 10));
	else if (len_flag && ft_strcmp(len_flag, "j") == 0)
		return (ft_itoa_base(va_arg(args, intmax_t), 10));
	else if (len_flag && ft_strcmp(len_flag, "z") == 0)
		return (ft_itoa_base(va_arg(args, size_t), 10));
	else if (len_flag && ft_strcmp(len_flag, "hh") == 0)
		return (ft_itoa_char(va_arg(args, int), 10));
	else
		return (ft_itoa_base(va_arg(args, int), 10));
}