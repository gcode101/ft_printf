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

static int	check_len_flags(char *format, int i)
{
	if (format[i] != 'l' && format[i] != 'h')
		return (1);
	if (format[i - 1] == 'l' && format[i - 2] == 'l')
		return (1);
	if (format[i - 1] == 'h' && format[i - 2] == 'h')
		return (1);
	return (0);
}

static int	end_of_format(char *format, int i)
{
	int			re;
	char		*converters;
	char		*len_flags;
	char		*flags;

	re = 0;
	converters = "sSpdDioOuUxXcC";
	len_flags = "hljz";
	flags = "#0-+ ";
	if (format[i] == '\0' || (i == 0 && ft_strchr(converters, format[i])))
	{
		// printf("%c\n", 'A');
		return (1);	
	}
	if (i == 0 && (is_valid(format[i]) || ft_isdigit(format[i])))
	{
		// printf("%c\n", 'B');
		return (0);
	}
	if (ft_strchr(converters, format[i]))
	{
		// printf("%c\n", 'C');
		re = 1;
	}
	else if (format[i] == '\n')
	{
		// printf("%c\n", 'D');
		re = 1;
	}
	else if (ft_strchr(len_flags, format[i - 1]))
	{
		// printf("%c\n", 'E');
		re = check_len_flags(format, i);
	}
	else if (ft_isdigit(format[i - 1]) && !ft_isdigit(format[i]) && format[i] != '.')
	{
		// printf("%c\n", 'F');
		if (!ft_strchr(flags, format[i - 1]))
			re = 1;
	}
	if (!re && !is_valid(format[i]) && !ft_isdigit(format[i]))
	{
		// printf("%c\n", 'G');
		re = 1;
	}
	if (format[i] == '%')
	{
		// printf("%c\n", 'H');
		re = 1;
	}	
	if (re && format[i + 1] == '\n')
		re = 0;
	// printf("format[%d]: %c\n", i, format[i]);
	// printf("re: %d\n", re);
	return (re);
}

int		format_reader(char **format, va_list args)
{
	int		i;
	int		c_printed;
	int		newline;
	int		conv_pos;
	char 	*subformat;

	// //printf("inside format_reader\n");
	i = 0;
	newline = 0;
	c_printed = 0;
	// printf("format: %s\n", *format);
	while (!end_of_format(*format, i))
		i++;
	subformat = ft_strsub(*format, 0, i + 1);
	if (ft_strchr(subformat, '\n'))
	{
		// //printf("%s\n", "subformat does have a newline");
		newline = 1;
		conv_pos = ft_strlen(subformat) - 2;	
	}
	else
		conv_pos = ft_strlen(subformat) - 1;
	// printf("subformat: {%s}\n", subformat);
	// //printf("subformat len: %zd\n", ft_strlen(subformat));
	// //printf("subformat[%d]: %c\n", conv_pos, subformat[conv_pos]);
	// if (ft_strchr(subformat, '%'))
	// {
	// 	ft_putchar('%');
	// 	c_printed++;
	// }
	*format = *format + i + 1;
	// //printf("subformat[%d]: %c\n", conv_pos, subformat[conv_pos]);
	// printf("format: %s\n", *format);
	if (subformat [conv_pos] == 's')
		c_printed += str_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'S')
		c_printed += str_conv(subformat, args, newline, 'S');	
	else if (subformat [conv_pos] == 'c')
		c_printed += chr_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'C')
		c_printed += chr_conv(subformat, args, newline, 'C');
	else if (subformat [conv_pos] == 'd' || subformat [conv_pos] == 'i')
		c_printed += decimal_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'D')
		c_printed += decimal_conv(subformat, args, newline, "l");	
	else if (subformat [conv_pos] == 'o')
		c_printed += octal_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'O')
		c_printed += octal_conv(subformat, args, newline, "l");	
	else if (subformat [conv_pos] == 'x')
		c_printed += hex_conv(subformat, args, newline, 0);
	else if (subformat [conv_pos] == 'X')
		c_printed += hex_conv(subformat, args, newline, 'X');
	else if (subformat [conv_pos] == 'p')
		c_printed += hex_conv(subformat, args, newline, 'p');
	else if (subformat [conv_pos] == 'u')
		c_printed += unsigned_conv(subformat, args, newline, NULL);
	else if (subformat [conv_pos] == 'U')
		c_printed += unsigned_conv(subformat, args, newline, "l");
	else
		c_printed += special_conv(subformat, newline);
	return (c_printed);
}
