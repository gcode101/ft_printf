/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:31:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 14:31:50 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				decimal_conv(char *format, va_list args, int newline, char *long_flag)
{
	int		num;
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;

	// printf("inside decimal_conv\n");
	if (long_flag)
		len_flag = long_flag;
	else
		len_flag = get_len_flag(format);
	arg = handle_dec_lenflag(len_flag, args);
	if (ft_strchr(arg, '-'))
		num = -1;
	else
		num = 1;
	c_printed = 0;
	flags = get_flags(format);
	modify_arg(format, flags, &arg, num);
	ft_putstr(arg);
	if (newline)
		ft_putchar('\n');
	return (c_printed);
}
