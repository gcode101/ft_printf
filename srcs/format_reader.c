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

static int	conv_help(char *subformat, int newline, int conv_pos, va_list args)
{
	int c_printed;

	c_printed = 0;
	if (subformat[conv_pos] == 'x')
		c_printed += hex_conv(subformat, args, newline, 0);
	else if (subformat[conv_pos] == 'X')
		c_printed += hex_conv(subformat, args, newline, 'X');
	else if (subformat[conv_pos] == 'p')
		c_printed += hex_conv(subformat, args, newline, 'p');
	else if (subformat[conv_pos] == 'u')
		c_printed += unsigned_conv(subformat, args, newline, NULL);
	else if (subformat[conv_pos] == 'U')
		c_printed += unsigned_conv(subformat, args, newline, "l");
	else
		c_printed += special_conv(subformat, newline);
	return (c_printed);
}

static int	conv(char *subformat, int newline, int conv_pos, va_list args)
{
	int	c_printed;

	c_printed = 0;
	if (subformat[conv_pos] == 's')
		c_printed += str_conv(subformat, args, newline, 0);
	else if (subformat[conv_pos] == 'S')
		c_printed += str_conv(subformat, args, newline, 'S');
	else if (subformat[conv_pos] == 'c')
		c_printed += chr_conv(subformat, args, newline, 0);
	else if (subformat[conv_pos] == 'C')
		c_printed += chr_conv(subformat, args, newline, 'C');
	else if (subformat[conv_pos] == 'd' || subformat[conv_pos] == 'i')
		c_printed += decimal_conv(subformat, args, newline, NULL);
	else if (subformat[conv_pos] == 'D')
		c_printed += decimal_conv(subformat, args, newline, "l");
	else if (subformat[conv_pos] == 'o')
		c_printed += octal_conv(subformat, args, newline, NULL);
	else if (subformat[conv_pos] == 'O')
		c_printed += octal_conv(subformat, args, newline, "l");
	else
		c_printed += conv_help(subformat, newline, conv_pos, args);
	return (c_printed);
}

int			format_reader(char **format, va_list args)
{
	int		i;
	int		c_printed;
	int		newline;
	int		conv_pos;
	char	*subformat;

	i = 0;
	newline = 0;
	while (!end_of_format(*format, i))
		i++;
	subformat = ft_strsub(*format, 0, i + 1);
	if (ft_strchr(subformat, '\n'))
	{
		newline = 1;
		conv_pos = ft_strlen(subformat) - 2;
	}
	else
		conv_pos = ft_strlen(subformat) - 1;
	*format = *format + i + 1;
	c_printed = conv(subformat, newline, conv_pos, args);
	return (c_printed);
}
