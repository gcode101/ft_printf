/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:12:34 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/17 13:22:53 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		numof_percent;
	int		c_printed;
	char	*format_cpy;
	char	*temp;

	c_printed = 0;
	format_cpy = ft_strdup(format);
	if ((numof_percent = percent_signs(format)) == 0)
	{
		ft_putstr(format);
		c_printed = ft_strlen(format);
	}
	va_start(args, format);
	while (numof_percent--)
	{
		if (ft_strlen(format_cpy) == 0)
			break ;
		temp = ft_strchr(format_cpy, '%');
		*temp = '\0';
		ft_putstr(format_cpy);
		c_printed += ft_strlen(format_cpy);
		format_cpy = ft_strdup(temp + 1);
		c_printed += format_reader(&format_cpy, args);
		if (!ft_strchr(format_cpy, '%'))
		{
			ft_putstr(format_cpy);
			c_printed += ft_strlen(format_cpy);
			break ;
		}
	}
	va_end(args);
	return (c_printed);
}
