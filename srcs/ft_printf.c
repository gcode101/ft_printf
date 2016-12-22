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

static int	new_temp(const char **temp, int i)
{
	int 		re;
	const char	*str;

	re = 0;
	str = *temp;
	// printf("inside new_temp\n");
	// printf("i: %d\n", i);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '%')
			break ;
		if (str[i] == '%')
		{
			// printf("looks like str[%d] equals percent_signs\n", i);
			re = 1;
			*temp = *temp + i + 1;
			// printf("new_temp: %s\n", *temp);
			break ;
		}
		i++;
	}
	return (re);
}

static int	percent_signs(const char * restrict str)
{
	int			i;
	int			ct;
	const char	*temp;

	i = 0;
	ct = 0;
	temp = str;
	// printf("temp: %s\n", temp);
	while (temp[i])
	{
		// printf("i: %d\n", i);
		if (temp[i] == '%' && temp[i + 1] == ' ')
		{
			if (new_temp(&temp, i + 1))
			{
				ct++;
				// printf("ct get incremented in A\n");
				i = -1;
			}
		}
		if (temp[i] == '%' && temp[i + 1] == '%')
		{
			// printf("i: %d\n", i);
			if (i >= 0)
			{
				// printf("%s\n", "ct gets incremented in B");
				ct++;
				temp = temp + i + 2;
				i = -1;
				// printf("temp: %s\n", temp);
			}
		}
		else if (i == 0 && temp[i] == '%')
		{
			ct++;
			// printf("ct get incremented in C\n");
			// printf("temp[%d]: %c\n", i, temp[i]);
			// printf("temp[%d - 1]: %c\n", i, temp[i - 1]);
		}
		else if (temp[i] == '%' && temp[i - 1] != '%')
		{
			// printf("i: %d\n", i);
			if (i >= 0)
			{
				// printf("%s\n", "ct gets incremented in D");
				ct++;
			}
		}
		i++;
	}
	// printf("percent_signs: %d\n", ct);
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
	{
		ft_putstr(format);
		c_printed = ft_strlen(format);
	}
	va_start(args, format);
	// printf("numof_percent: %d\n", numof_percent);
	while (numof_percent--)
	{
		// printf("format_cpy: %s\n", format_cpy);
		if (ft_strlen(format_cpy) == 0)
			break ;
		temp = ft_strchr(format_cpy, '%');
		*temp = '\0';
		//printf("-this gets printed out");
		ft_putstr(format_cpy);
		//printf("\n");
		c_printed += ft_strlen(format_cpy);
		format_cpy = ft_strdup(temp + 1);
		// printf("after temp format_cpy: %s\n", format_cpy);
		c_printed += format_reader(&format_cpy, args);
		// printf("c_printed: %d\n", c_printed);
		if (!ft_strchr(format_cpy, '%'))
		{
			ft_putstr(format_cpy);
			c_printed += ft_strlen(format_cpy);
			break ;
		}
	}
	// printf("returning c_printed: %d\n", c_printed);
		va_end(args);
	return (c_printed);
}
