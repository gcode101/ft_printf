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

static void	handle_positive_num(char **arg, int space_flag)
{
	char	*temp;
	char	*str;
	int		i;

	i = 0;
	str = *arg;
	if ((temp = ft_strchr(str, '+')))
	{
		*temp = '0';
		str[0] = '+';
		i = 1;
	}
	if (space_flag)
		i = 1;
	while (str[i] == ' ')
		str[i++] = '0';
}

void		zero_flag(char **arg, int num, int space_flag)
{
	int		i;
	char	*str;

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
		handle_positive_num(arg, space_flag);
}
