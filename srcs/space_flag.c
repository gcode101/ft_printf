/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 10:21:53 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/19 10:21:54 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_flag(char **arg, int precision)
{
	int		i;
	int		len;
	char	*str;
	char	*temp;

	i = 0;
	str = *arg;
	len = ft_strlen(str);
	if ((str[0] == '0') && !precision)
		str[0] = ' ';
	else if (str[0] != ' ')
	{
		if ((temp = ft_strnew(len + 1)))
		{
			ft_memset(temp, ' ', len + 1);
			i = len - 1;
			while (len)
			{
				temp[i + 1] = str[i];
				i--;
				len--;
			}
			*arg = temp;
		}
	}
}
