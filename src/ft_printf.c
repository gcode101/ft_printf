/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:12:34 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/17 13:22:53 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;
	char	*str;	

	va_start(args, format);
	while (1)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			break ;
		ft_putendl(str);
	}
	va_end(args);
	return (0);
}
