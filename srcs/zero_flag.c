/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:57:46 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/08 10:57:48 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_flag(char **arg, int num)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	str = *arg;
	if (num < 0)
	{
		if (str[i] == ' ')
			str[i++] = '-';
		while (str[i] == ' ' || str[i] == '-')
			str[i++] = '0';
	}
	else
	{
		if ((temp = ft_strchr(str, '+')))
		{
			*temp = '0';
			str[0] = '+';
			i = 1;
		}
		while (str[i] == ' ')
			str[i++] = '0';
	}
}
