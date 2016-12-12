/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:32:22 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 12:32:24 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_wchar_str(char *len_flag, va_list args, int newline, char *format)
{
	wchar_t *str;
	int		presicion;
	char	*flags;
	int		i;

	i = -1;
	if (ft_strcmp(len_flag, "l") == 0)
	{
		str = va_arg(args, wchar_t *);
		presicion = get_pre(format);
		flags = get_flags(format);
		if (presicion >= 0 && presicion < ft_wstrlen(str))
			str = ft_wstrsub(str, 0, presicion);
		handle_wchar_width(format, &str);
		handle_wflags(flags, &str);
		while (str[++i])
			ft_putwchar(str[i]);
		if (newline)
			ft_putchar('\n');
	}
	return (i);
}