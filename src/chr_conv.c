/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:21:16 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 11:21:18 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			chr_conv(char *format, va_list args, int newline, char cap_c)
{
	int		c_printed;
	char	arg;
	char	*str;
	char	*len_flag;
	char	*flags;

	c_printed = -1;
	len_flag = get_len_flag(format);
	if (cap_c || len_flag)
		c_printed = handle_wchar(len_flag, args, newline, format);
	else
	{
		arg = va_arg(args, int);
		flags = get_flags(format);
		if (get_width(format))
		{
			if (!(str = malloc(sizeof(wchar_t) * 2)))
				return (-1);
			str[0] = arg;
			str[1] = '\0';
			handle_width(format, &str, 0);
			handle_flags(format, flags, &str, 0);
			ft_putstr(str);
			c_printed = ft_strlen(str);
		}
		else
		{
			ft_putwchar(arg);
			c_printed = 1;
		}
		if (newline)
			ft_putchar('\n');
	}
	return (c_printed);
}
