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

static int	percent_signs(const char * restrict str)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i - 1] != '%')
			ct++;
		i++;
	}
	return (ct);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	args;
	// char	*str;
	int		numof_percent;
	int		c_printed;
	char 	*format_cpy;
	char 	*temp;

	c_printed = 0;
	// printf("inside ft_printf\n");
	format_cpy = ft_strdup(format);
	if ((numof_percent = percent_signs(format)) == 0)
		ft_putstr(format);
	c_printed = ft_strlen(format);
	va_start(args, format);
	// printf("numof_percent: %d\n", numof_percent);
	while (numof_percent--)
	{
		//printf("before temp format_cpy: %s\n", format_cpy);
		temp = ft_strchr(format_cpy, '%');
		*temp = '\0';
		//printf("-this gets printed out");
		ft_putstr(format_cpy);
		//printf("\n");
		c_printed += ft_strlen(format_cpy);
		format_cpy = ft_strdup(temp + 1);
		// printf("after temp format_cpy: %s\n", format_cpy);
		c_printed += format_reader(&format_cpy, args);
		if (!ft_strchr(format_cpy, '%'))
			ft_putstr(format_cpy);
	}
	va_end(args);
	return (c_printed);
}
