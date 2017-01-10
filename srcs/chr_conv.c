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

static int	print_width(char *format, char arg, int width)
{
	int		c_printed;
	char	*flags;
	char	*str;

	c_printed = 0;
	if ((width = get_width(format)))
	{
		flags = get_flags(format);
		if (!(str = malloc(sizeof(wchar_t) * 2)))
			return (-1);
		str[0] = arg;
		str[1] = '\0';
		if (!arg)
		{
			width--;
			c_printed++;
		}
		handle_width(format, &str, width);
		handle_flags(format, flags, &str, 0);
		if (ft_strchr(flags, '0') && ft_strchr(format, '.'))
			zero_flag(&str, 0, 0);
		ft_putstr(str);
		c_printed += ft_strlen(str);
	}
	return (c_printed);
}

int			chr_conv(char *format, va_list args, int newline, char cap_c)
{
	int		c_printed;
	int		width;
	char	arg;
	char	*len_flag;

	c_printed = 0;
	width = 0;
	len_flag = get_len_flag(format);
	if (cap_c)
		c_printed = handle_wchar("l", args, newline, format);
	else if (len_flag)
		c_printed = handle_wchar(len_flag, args, newline, format);
	else
	{
		arg = va_arg(args, int);
		if (!(c_printed = print_width(format, arg, width)))
			c_printed = print_chr(arg);
		if (newline)
			c_printed += print_chr('\n');
	}
	return (c_printed);
}
