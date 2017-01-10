/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:56:04 by gcortina          #+#    #+#             */
/*   Updated: 2017/01/10 12:56:05 by gcortina         ###   ########.fr       */
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

static int	format_helper(char *format, int i, char *conv, char *len_flags)
{
	int		re;
	char	*flags;

	flags = "#0-+ ";
	re = 0;
	if (format[i] == '\0' || (i == 0 && ft_strchr(conv, format[i])))
		return (1);
	if (i == 0 && (is_valid(format[i]) || ft_isdigit(format[i])))
		return (0);
	if (ft_strchr(conv, format[i]))
		re = 1;
	else if (format[i] == '\n')
		re = 1;
	else if (ft_strchr(len_flags, format[i - 1]))
		re = check_len_flags(format, i);
	else if (ft_isdigit(format[i - 1]) && !ft_isdigit(format[i])
				&& format[i] != '.')
	{
		if (!ft_strchr(flags, format[i - 1]))
			re = 1;
	}
	return (re);
}

int			end_of_format(char *format, int i)
{
	int			re;
	char		*converters;
	char		*len_flags;

	re = 0;
	converters = "sSpdDioOuUxXcC";
	len_flags = "hljz";
	re = format_helper(format, i, converters, len_flags);
	if (!re && !is_valid(format[i]) && !ft_isdigit(format[i]))
		re = 1;
	if (format[i] == '%')
		re = 1;
	if (re && format[i + 1] == '\n')
		re = 0;
	return (re);
}
