/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:55:06 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/28 13:55:08 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flags(char *format)
{
	char	*flags;
	int		i;

	i = 0;
	if (!(flags = ft_strnew(1)))
		return (NULL);
	while (format[i])
	{
		if (ft_isdigit(format[i]) && format[i] != '0')
			break ;
		if (format[i] == '#' && !ft_strchr(flags, '#'))
			flags = ft_strjoin(flags, "#");
		if (format[i] == '0' && !ft_strchr(flags, '0'))
			flags = ft_strjoin(flags, "0");
		if (format[i] == '-' && !ft_strchr(flags, '-'))
			flags = ft_strjoin(flags, "-");
		if (format[i] == '+' && !ft_strchr(flags, '+'))
			flags = ft_strjoin(flags, "+");
		if (format[i] == ' ' && !ft_strchr(flags, ' '))
			flags = ft_strjoin(flags, " ");		
		i++;							
	}
	return (flags);
}
