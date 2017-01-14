/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:31:21 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/22 15:31:23 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printout(char *arg, char *format, char *flags, int newline)
{
	int	presicion;
	int	c_printed;

	presicion = get_pre(format);
	c_printed = 0;
	if (!arg)
		return (0);
	if (presicion >= 0 && presicion < (int)ft_strlen(arg))
		arg = ft_strsub(arg, 0, presicion);
	handle_width(format, &arg, 0);
	handle_flags(format, flags, &arg, 0);
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
		c_printed += print_chr('\n');
	return (c_printed);
}

static int	p_empty_str(char *format, char *flags)
{
	int		c_printed;
	char	*arg;

	c_printed = 0;
	if (get_width(format) && ft_strchr(format, '.'))
	{
		arg = "";
		handle_width(format, &arg, 0);
		handle_flags(format, flags, &arg, 0);
		if (ft_strchr(flags, '0') && ft_strchr(format, '.'))
			zero_flag(&arg, 0, 0);
		ft_putstr(arg);
		c_printed = ft_strlen(arg);
	}
	else if (!ft_strchr(format, '.'))
	{
		ft_putstr("(null)");
		c_printed += 6;
	}
	return (c_printed);
}

int			str_conv(char *format, va_list args, int newline, char cap_s)
{
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;

	c_printed = 0;
	len_flag = get_len_flag(format);
	if (cap_s)
		c_printed = handle_wchar_str("l", args, newline, format);
	else if (len_flag)
		c_printed = handle_wchar_str(len_flag, args, newline, format);
	else
	{
		flags = get_flags(format);
		if ((arg = va_arg(args, char *)))
			c_printed += printout(arg, format, flags, newline);
		else
			c_printed += p_empty_str(format, flags);
	}
	return (c_printed);
}
