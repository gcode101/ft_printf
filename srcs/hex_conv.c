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

static void	hash_flag_helper(char **arg, int shift)
{
	char	*str;
	int		i;

	i = 0;
	str = *arg;
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

static void	hash_flag(char *format, char **arg, int arg_len, char p)
{
	int		len;
	int		width;
	int		shift;
	int		precision;

	shift = 2;
	if (p != 'p' && (ft_strcmp(*arg, "0") == 0 || ft_strlen(*arg) == 0))
		return ;
	precision = get_pre(format);
	width = get_width(format);
	if ((width >= arg_len + 2) && width >= precision + 2)
		len = ft_strlen(*arg);
	else if ((width == arg_len + 1 && width > precision) ||
			(width == precision + 1 && precision >= arg_len))
	{
		len = ft_strlen(*arg) + 1;
		shift = 1;
	}
	else
		len = ft_strlen(*arg) + 2;
	handle_width(format, arg, len);
	hash_flag_helper(arg, shift);
}

static int	printout(char *arg, char x_or_p, int newline)
{
	int		i;
	int		c_printed;

	i = -1;
	c_printed = 0;
	if (x_or_p == 'X')
		while (arg[++i])
			arg[i] = ft_toupper(arg[i]);
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
		c_printed += print_chr('\n');
	return (c_printed);
}

int			hex_conv(char *format, va_list args, int newline, char x_or_p)
{
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
	return (printout(arg, x_or_p, newline));
}
