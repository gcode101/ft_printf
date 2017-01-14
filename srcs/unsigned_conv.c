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

static int	printout(char *format, char *arg, int newline)
{
	int		c_printed;
	int		num;
	char	*flags;
	char	*temp;

	c_printed = 0;
	flags = get_flags(format);
	if (ft_strchr(arg, '-'))
		num = -1;
	else
		num = 1;
	if ((temp = ft_strchr(flags, ' ')))
		*temp = '^';
	if ((temp = ft_strchr(flags, '+')))
		*temp = '^';
	modify_arg(format, flags, &arg, num);
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
		c_printed += print_chr('\n');
	return (c_printed);
}

int			unsigned_conv(char *format, va_list args, int newline, char *lflag)
{
	char	*arg;
	char	*len_flag;

	if (lflag)
		len_flag = lflag;
	else
		len_flag = get_len_flag(format);
	arg = handle_un_lenflag(len_flag, args, 10);
	return (printout(format, arg, newline));
}
