/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_un_lenflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:42:57 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 14:42:59 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_char(int index)
{
	char	*str;

	str = "0123456789abcdef";
	return (str[index]);
}

static int	get_digits(unsigned long long num, int base)
{
	unsigned long long	nb;
	int					digits;

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

static char *unsigned_itoa_base(unsigned long long value, int base)
{
	unsigned long long	num;
	int					digits;
	char				*re;

	num = value;
	digits = get_digits(num, base);
	if (!(re = malloc(sizeof(char) * digits + 1)))
		return (NULL);
	re[digits] = '\0';
	digits--;
	while (digits >= 0)
	{
		re[digits--] = get_char(num % base);
		num /= base;
	}
	return (re);
}

#include "ft_printf.h"

char	*handle_un_lenflag(char *len_flag, va_list args, int base)
{
	unsigned long num;

	if (len_flag && ft_strcmp(len_flag, "l") == 0)
		return (unsigned_itoa_base(va_arg(args, unsigned long), base));
	else if (len_flag && ft_strcmp(len_flag, "ll") == 0)
		return (unsigned_itoa_base(va_arg(args, unsigned long long), base));
	else if (len_flag && ft_strcmp(len_flag, "j") == 0)
		return (unsigned_itoa_base(va_arg(args, intmax_t), base));
	else if (len_flag && ft_strcmp(len_flag, "z") == 0)
		return (unsigned_itoa_base(va_arg(args, size_t), base));
	else if (len_flag && ft_strcmp(len_flag, "p") == 0)
	{
		num = (unsigned long)va_arg(args, void*);
		return (unsigned_itoa_base(num, base));
	}
	else
		return (unsigned_itoa_base(va_arg(args, unsigned int), base));
}
