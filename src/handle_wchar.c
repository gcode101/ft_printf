/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:57:13 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/06 11:57:15 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_wchar(char *len_flag, va_list args, int newline, char *format)
{
	wchar_t chr;
	wchar_t *str;
	char	*flags;
	int		i;

	i = -1;
	if (ft_strcmp(len_flag, "l") == 0)
	{
		chr = (wchar_t)va_arg(args, wint_t);
		flags = get_flags(format);
		if (get_width(format))
		{
			if (!(str = malloc(sizeof(wchar_t) * 2)))
				return (-1);
			str[0] = chr;
			str[1] = '\0';
			handle_wchar_width(format, &str);
			handle_wflags(flags, &str);
			while (str[++i])
				ft_putwchar(str[i]);
		}
		else
		{
			ft_putwchar(chr);
			i = 1;
		}
		if (newline)
			ft_putchar('\n');
	}
	return (i);
}
