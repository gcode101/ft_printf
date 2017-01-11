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

static int	print_width(wchar_t chr, char *format, char *flags)
{
	wchar_t *str;
	int		ct;
	int		i;

	ct = 0;
	i = -1;
	if (!(str = malloc(sizeof(wchar_t) * 2)))
		return (-1);
	str[0] = chr;
	str[1] = '\0';
	handle_wchar_width(format, &str);
	handle_wflags(flags, &str);
	while (str[++i])
		ct += print_wchr(str[i]);
	return (ct);
}

int			handle_wchar(char *len_flag, va_list args,
								int newline, char *format)
{
	wchar_t chr;
	char	*flags;
	int		ct;

	ct = 0;
	if (ft_strcmp(len_flag, "l") == 0)
	{
		chr = (wchar_t)va_arg(args, wint_t);
		flags = get_flags(format);
		if (get_width(format))
			ct += print_width(chr, format, flags);
		else
			ct += print_wchr(chr);
		if (newline)
			ct += print_chr('\n');
	}
	return (ct);
}
