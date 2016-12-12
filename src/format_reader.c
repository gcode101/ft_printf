/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:07:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/28 14:07:48 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	end_of_format(char *format, int i)
{
	int			re;

	re = 0;
	// printf("inside end_of_format\n");
	// printf("format: %s\n", format);
	// printf("i: %d\n", i);
	if (format[i] == '\0' || format[i] == 's' || format[i] == 'S')
		re = 1;
	else if (format[i] == 'p' || format[i] == 'd' || format[i] == 'D')
		re = 1;
	else if (format[i] == 'i' || format[i] == 'o' || format[i] == 'O')
		re = 1;
	else if (format[i] == 'u' || format[i] == 'U' || format[i] == 'x')
		re = 1;
	else if (format[i] == 'X' || format[i] == 'c' || format[i] == 'C')
		re = 1;
	else if (format[i] == '\n')
		re = 1;
	if (re && format[i + 1] == '\n')
	{
		// printf("format[i + 1] = %c\n", format[i + 1]);
		re = 0;
	}
	return (re);
}

int		format_reader(char **format, va_list args)
{
	int		i;
	int		c_printed;
	int		newline;
	int		conv_pos;
	char 	*subformat;

	// printf("inside format_reader\n");
	i = 0;
	newline = 0;
	c_printed = -1;
	// printf("format: %s\n", *format);
	while (!end_of_format(*format, i))
		i++;
	subformat = ft_strsub(*format, 0, i + 1);
	if (ft_strchr(subformat, '\n'))
	{
		// printf("%s\n", "subformat does have a newline");
		newline = 1;
		conv_pos = ft_strlen(subformat) - 2;	
	}
	else
		conv_pos = ft_strlen(subformat) - 1;
	// printf("subformat: %s\n", subformat);
	if (ft_strchr(subformat, '%'))
		ft_putchar('%');
	*format = *format + i + 1;
	// printf("format: %s\n", *format);
	if (subformat [conv_pos] == 's')
		c_printed = str_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'S')
		c_printed = str_conv(subformat, args, newline, 'S');	
	else if (subformat [conv_pos] == 'c')
		c_printed = chr_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'C')
		c_printed = chr_conv(subformat, args, newline, 'C');
	else if (subformat [conv_pos] == 'd' || subformat [conv_pos] == 'i')
		c_printed = decimal_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'D')
		c_printed = decimal_conv(subformat, args, newline, "l");	
	else if (subformat [conv_pos] == 'o')
		c_printed = octal_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'O')
		c_printed = octal_conv(subformat, args, newline, "l");	
	else if (subformat [conv_pos] == 'x')
		c_printed = hex_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'X')
		c_printed = hex_conv(subformat, args, newline, 'X');
	else if (subformat [conv_pos] == 'p')
		c_printed = hex_conv(subformat, args, newline, 'p');
	else if (subformat [conv_pos] == 'u')
		c_printed = unsigned_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'U')
		c_printed = unsigned_conv(subformat, args, newline, "l");
	return (c_printed);
}
