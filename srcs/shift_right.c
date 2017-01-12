/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:39:08 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/14 12:39:09 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		shift_right(char *str, int num)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i] && str[i] == ' ')
		i--;
	if ((i + num) >= len)
		return (0);
	while (i >= 0)
	{
		str[i + num] = str[i];
		i--;
	}
	i = 0;
	while (num--)
		str[i++] = ' ';
	return (1);
}
