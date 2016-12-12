/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:18:30 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 14:18:32 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		modify_arg(char *format, char *flags, char **arg, int num)
{
	int		presicion;
	int		width;

	presicion = get_pre(format);
	if (presicion < 0)
		presicion = 0;
	width = get_width(format);
	if (presicion > (int)ft_strlen(*arg))
	{
		if (num < 0)
			presicion++;
		handle_width(format, arg, presicion);
		zero_flag(arg, num);
	}
	handle_width(format, arg, 0);
	handle_flags(format, flags, arg, num);
}