/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:48:05 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/14 22:48:07 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		special_conv(char *format, int newline)
{
	int		c_printed;
	int		i;
	char	*arg;
	char	*flags;

	i = 0;
	arg = format;
	flags = get_flags(format);
	while (arg[i])
	{
		if (!is_valid(arg[i]) && !ft_isdigit(arg[i]))
			break ;
		i++;
	}
	arg = &arg[i];
	if (get_width(format))
		handle_width(format, &arg, 0);
	handle_flags(format, get_flags(format), &arg, 0);
	if (ft_strchr(flags, '0') && ft_strchr(format, '.'))
		zero_flag(&arg, 0, 0);	
	ft_putstr(arg);
	c_printed = ft_strlen(arg);
	if (newline)
	{
		ft_putchar('\n');
		c_printed++;
	}
	return (c_printed);
}
