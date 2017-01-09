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
	int		ct;

	i = -1;
	ct = 0;
	// printf("%s\n", "inside handle_wchar_str");
	if (ft_strcmp(len_flag, "l") == 0)
	{
		flags = get_flags(format);
		if ((str = va_arg(args, wchar_t *)))
		{
			// printf("str: {%S}\n", str);
			presicion = get_pre(format);
			// printf("presicion: %d\n", presicion);
			// printf("str length: %zd\n", ft_wstrlen(str));
			if (presicion >= 0 && presicion < ft_wstrlen(str))
			{
				// printf("%s\n", "inside presicion");
				str = ft_wstrsub(str, 0, presicion);
				// while (str[++i])
				// 	ft_putwchar(str[i]);
				// ft_putchar('\n');
				// i = -1;			
			}
			// printf("str: {%S}\n", str);
			handle_wchar_width(format, &str);
			// printf("str: {%S}\n", str);
			handle_wflags(flags, &str);
			while (str[++i])
			{
				ft_putwchar(str[i]);
				ct += wchr_len(str[i]);
			}
			if (newline)
				ft_putchar('\n');
		}
		else
		{
			if (get_width(format) && ft_strchr(format, '.'))
			{
				str = L"";
				handle_wchar_width(format, &str);
				handle_wflags(format, &str);
				i = 0;
				if (ft_strchr(flags, '0') && ft_strchr(format, '.'))
					while (str[i] == ' ')
						str[i++] = '0';
				i = -1;
				while (str[++i])
				{
					ft_putwchar(str[i]);
					ct += wchr_len(str[i]);
				}
			}
			else if (!ft_strchr(format, '.'))
			{
				ft_putstr("(null)");
				ct += 6;
			}
		}
	}
	return (ct);
}
