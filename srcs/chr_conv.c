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
	int		width;
	char	arg;
	char	*str;
	char	*len_flag;
	char	*flags;

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
		// printf("arg: {%c}\n", arg);
		flags = get_flags(format);
		// printf("flags: %s\n", flags);
		if ((width = get_width(format)))
		{
			// printf("width: %d\n", width);
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
		else
		{
			ft_putwchar(arg);
			c_printed = 1;
		}
		if (newline)
		{
			ft_putchar('\n');
			c_printed++;
		}
	}
	return (c_printed);
}
