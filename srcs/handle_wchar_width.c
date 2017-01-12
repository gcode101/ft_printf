/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:30:01 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 12:30:04 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_wchar_width(char *format, wchar_t **arg)
{
	int		width;
	int		i;
	int		len;
	wchar_t	*temp;
	wchar_t	*str;

	width = get_width(format);
	str = *arg;
	len = 0;
	len = ft_wstrlen(str);
	if (len == 0)
		len = 0;
	else
		len = (width - len);
	if (width > ft_wstrlen(str))
	{
		i = ft_wstrlen(str) - 1;
		if ((temp = malloc(sizeof(wchar_t) * width + 1)))
		{
			ft_wmemset(temp, ' ', width);
			while (i >= 0)
				temp[--width] = str[i--];
			*arg = temp;
		}
	}
}
