/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:17:21 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/28 12:17:22 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_pre(char *format)
{
	int		pre;
	int		i;
	int		start;

	i = 0;
	pre = -1;
	while (format[i])
	{
		if (format[i++] == '.')
		{
			start = i;
			while (ft_isdigit(format[i]))
				i++;
			pre = ft_atoi(ft_strsub(format, start, i - start));
		}
	}
	return (pre);
}
