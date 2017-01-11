/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:25:32 by gcortina          #+#    #+#             */
/*   Updated: 2017/01/11 13:36:19 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits_short(unsigned short int num, int base)
{
	unsigned short int	nb;
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

char		*unsigned_itoa_short(unsigned short int value, int base)
{
	unsigned short int	num;
	int					digits;
	char				*re;

	num = value;
	digits = get_digits_short(num, base);
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
