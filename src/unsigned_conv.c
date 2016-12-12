/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:40:20 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 14:40:22 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_conv(char *format, va_list args, int newline, char *long_flag)
{
	int		num;
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;

	if (long_flag)
		len_flag = long_flag;
	else
		len_flag = get_len_flag(format);
	arg = handle_un_lenflag(len_flag, args, 10);
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
