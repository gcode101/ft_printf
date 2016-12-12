/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:26:58 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 14:27:00 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hash_flag(char *format, char **arg, char *flags)
{
	char	*str;
	int		len;
	int		arg_len;
	int		width;
	int		i;

	i = 0;
	width = get_width(format);
	arg_len = ft_strlen(*arg);
	if (((ft_strchr(flags, '0') && !ft_strchr(flags, '-')) && width == arg_len) ||
		(width == arg_len && !ft_strchr(flags, '-')))
			len = ft_strlen(*arg);
	else
		len = ft_strlen(*arg) + 2;
	handle_width(format, arg, len);
	str = *arg;
	if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	else
		str[1] = 'x';
}

int		hex_conv(char *format, va_list args, int newline, char x_or_p)
{
	int		i;
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;

	flags = get_flags(format);
	if (x_or_p == 'p')
	{
		len_flag = "p";
		flags = ft_strjoin(flags, "#");
	}
	else
		len_flag = get_len_flag(format);
	arg = handle_un_lenflag(len_flag, args, 16);
	c_printed = 0;
	modify_arg(format, flags, &arg, 0);
	if (ft_strchr(flags, '#'))
		hash_flag(format, &arg, flags);
	i = -1;
	if (x_or_p == 'X')
		while (arg[++i])
			arg[i] = ft_toupper(arg[i]);
	ft_putstr(arg);
	if (newline)
		ft_putchar('\n');
	return (c_printed);	
}
