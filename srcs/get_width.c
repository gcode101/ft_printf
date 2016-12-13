/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:44:28 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/06 13:44:29 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(char *format)
{
	int		i;
	int		start;
	int		width;

	i = 0;
	width = 0;
	while (format[i] && format[i] != '.')
	{
		if (ft_isdigit(format[i]) && format[i] != '0')
		{
			start = i;
			while (format[i] != '.' && ft_isdigit(format[i]))
				i++;
			width = ft_atoi(ft_strsub(format, start, i - start));
			break ;
		}
		i++;
	}
	return (width);
}
