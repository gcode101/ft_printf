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

static void	hash_flag(char *format, char **arg)
{
	int		len;

	len = ft_strlen(*arg) + 1;
	handle_width(format, arg, len);
	zero_flag(arg, 0);
}

int		octal_conv(char *format, va_list args, int newline, char *long_flag)
{
	int		c_printed;
	char	*arg;
	char	*len_flag;
	char	*flags;

	if (long_flag)
		len_flag = long_flag;
	else
		len_flag = get_len_flag(format);
	arg = handle_un_lenflag(len_flag, args, 8);
	c_printed = 0;
	flags = get_flags(format);
	if (ft_strchr(flags, '#'))
		hash_flag(format, &arg);
	modify_arg(format, flags, &arg, 0);
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
		ft_putchar('\n');
	return (c_printed);	
}
