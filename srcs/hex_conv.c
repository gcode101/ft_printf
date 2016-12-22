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

static void	hash_flag(char *format, char **arg, int arg_len, char p)
{
	char	*str;
	int		len;
	int		width;
	int		i;
	int		shift;
	int		precision;

	i = 0;
	shift = 2;
	// printf("arg: %s\n", *arg);
	if (p != 'p' && (ft_strcmp(*arg, "0") == 0 || ft_strlen(*arg) == 0))
		return ;
	// if ((precision = get_pre(format)) == -1)
	// 	precision = 0;
	precision = get_pre(format);
	// printf("arg: {%s}\n", *arg);
	// printf("arg_len: %zd\n", ft_strlen(*arg));
	width = get_width(format);
	// printf("width: %d\n", width);
	// printf("precision: %d\n", precision);
	if ((width >= arg_len + 2) && width >= precision + 2)
		len = ft_strlen(*arg);
	else if ((width == arg_len + 1 &&  width > precision) || (width == precision + 1
		&& precision >= arg_len))
	{
		len = ft_strlen(*arg) + 1;
		shift = 1;
	}
	else
		len = ft_strlen(*arg) + 2;
	// printf("len: %d\n", len);
	handle_width(format, arg, len);
	str = *arg;
	// printf("str: {%s}\n", str);
	// printf("shift: %d\n", shift);
	shift_right(str, shift);
	if (str[0] == ' ' && str[1] == ' ')
	{
		while (str[i] == ' ')
			i++;
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	else
	{
		str[0] = '0';
		str[1] = 'x';
	}
}

int		hex_conv(char *format, va_list args, int newline, char x_or_p)
{
	int		i;
	int		c_printed;
	int		arg_len;
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
	arg_len = ft_strlen(arg);
	c_printed = 0;
	modify_arg(format, flags, &arg, 0);
	if (ft_strchr(flags, '#'))
		hash_flag(format, &arg, arg_len, x_or_p);
	i = -1;
	if (x_or_p == 'X')
		while (arg[++i])
			arg[i] = ft_toupper(arg[i]);
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
	{
		ft_putchar('\n');
		c_printed++;
	}
	return (c_printed);	
}
