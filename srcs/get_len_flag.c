/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:17:34 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/28 12:17:36 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_len_flag(char *format)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (format[i])
	{
		if (format[i] == 'h' && format[i + 1] == 'h')
			return ((result = ft_strdup("hh")));
		if (format[i] == 'h')
			return ((result = ft_strdup("h")));
		if (format[i] == 'l' && format[i + 1] == 'l')
			return ((result = ft_strdup("ll")));
		if (format[i] == 'l')
			return ((result = ft_strdup("l")));
		if (format[i] == 'j')
			return ((result = ft_strdup("j")));
		if (format[i] == 't')
			return ((result = ft_strdup("t")));
		if (format[i] == 'z')
			return ((result = ft_strdup("z")));										
		i++;
	}
	return (result);
}
