/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:22:34 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 14:22:36 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hash_flag(char *format, char **arg, int arg_len)
{
	int		i;
	int		len;
	int		width;
	int		presicion;
	char	*str;

	i = 0;
	// printf("arg: {%s}\n", *arg);
	width = get_width(format);
	presicion = get_pre(format);
	if (presicion < 0)
		presicion = 0;
	len = ft_strlen(*arg);
	str = *arg;
	if (ft_strcmp(*arg, "0") == 0)
		return ;
	while (str[i] == ' ')
		i++;
	if (width > arg_len || presicion > arg_len)
	{
		if (i > 0 && str[i - 1] == ' ' && presicion <= arg_len)
			str[i - 1] = '0';
	}
	else
	{
		if (width <= arg_len)
			len = ft_strlen(*arg) + 1;
		handle_width(format, arg, len);
		zero_flag(arg, 0, 0);
	}
}

int		octal_conv(char *format, va_list args, int newline, char *long_flag)
{
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;
	int		arg_len;

	if (long_flag)
		len_flag = long_flag;
	else
		len_flag = get_len_flag(format);
	arg = handle_un_lenflag(len_flag, args, 8);
	arg_len = ft_strlen(arg);
	c_printed = 0;
	flags = get_flags(format);
	modify_arg(format, flags, &arg, 0);
	if (ft_strchr(flags, '#'))
		hash_flag(format, &arg, arg_len);	
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
	{
		ft_putchar('\n');
		c_printed++;
	}
	return (c_printed);	
}
