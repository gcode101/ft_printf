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

int			str_conv(char *format, va_list args, int newline, char cap_s)
{
	int		c_printed;
	char	*arg;
	int		presicion;
	char	*len_flag;
	char	*flags;

	c_printed = 0;
	len_flag = get_len_flag(format);
	if (cap_s || len_flag)
		c_printed = handle_wchar_str(len_flag, args, newline, format);
	else
	{
		presicion = get_pre(format);
		flags = get_flags(format);
		arg = va_arg(args, char *);
		if (presicion >= 0 && presicion < (int)ft_strlen(arg))
			arg = ft_strsub(arg, 0, presicion);
		handle_width(format, &arg, 0);
		handle_flags(format, flags, &arg, 0);
		if (newline)
			ft_putendl(arg);
		else
			ft_putstr(arg);
	}
	return (c_printed);
}
