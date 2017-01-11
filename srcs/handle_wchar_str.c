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

static int	print_wstring(char *format, wchar_t *str, char *flags, int newline)
{
	int		ct;
	int		i;
	int		presicion;

	ct = 0;
	i = -1;
	presicion = get_pre(format);
	if (presicion >= 0 && presicion < ft_wstrlen(str))
		str = ft_wstrsub(str, 0, presicion);
	handle_wchar_width(format, &str);
	handle_wflags(flags, &str);
	while (str[++i])
		ct += print_wchr(str[i]);
	if (newline)
		ct += print_chr('\n');
	return (ct);
}

static int	p_empt_str(char *format, wchar_t *str, char *flags)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	str = L"";
	handle_wchar_width(format, &str);
	handle_wflags(format, &str);
	if (ft_strchr(flags, '0') && ft_strchr(format, '.'))
		while (str[i] == ' ')
			str[i++] = '0';
	i = -1;
	while (str[++i])
		ct += print_wchr(str[i]);
	return (ct);
}

int			handle_wchar_str(char *len_flag, va_list args,
								int newline, char *format)
{
	wchar_t *str;
	char	*flags;
	int		ct;

	ct = 0;
	if (ft_strcmp(len_flag, "l") == 0)
	{
		flags = get_flags(format);
		if ((str = va_arg(args, wchar_t *)))
			ct += print_wstring(format, str, flags, newline);
		else
		{
			if (get_width(format) && ft_strchr(format, '.'))
				ct += p_empt_str(format, str, flags);
			else if (!ft_strchr(format, '.'))
			{
				ft_putstr("(null)");
				ct += 6;
			}
		}
	}
	return (ct);
}
