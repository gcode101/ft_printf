/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:24:51 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/02 13:24:53 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_width(char *format, char **arg, int size)
{
	int		width;
	int		i;
	char	*temp;
	char	*str;

	if (size)
		width = size;
	else
		width = get_width(format);
	str = *arg;
	if (width > (int)ft_strlen(str))
	{
		i = ft_strlen(str) - 1;
		if ((temp = ft_strnew(width)))
		{
			ft_memset(temp, ' ', width);
			while (i >= 0)
				temp[--width] = str[i--];
			*arg = temp;
		}
	}
}
