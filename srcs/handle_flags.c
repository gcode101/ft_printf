/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:16:33 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/06 14:16:35 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	minos_flag(char **arg)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;

	str = *arg;
	i = 0;
	j = 0;
	if ((temp = ft_strdup(str)))
	{
		while (temp[i] == ' ')
			i++;
		while (temp[i])
			str[j++] = temp[i++];
		while (str[j])
			str[j++] = ' ';
		ft_memdel((void**)&temp);
	}
}

static void	plus_flag(char **arg, int precision)
{
	int		i;
	int		len;
	char	*str;
	char	*temp;

	i = 0;
	str = *arg;
	len = ft_strlen(str);
	if ((str[0] == '0') && !precision)
		str[0] = '+';
	else if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
		str[i - 1] = '+';
	}
	else
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
			temp[i + 1] = '+';
			*arg = temp;
		}
	}
}

void		handle_flags(char *format, char *flags, char **arg, int num)
{
	int		i;
	int		precision;

	i = 0;
	if ((precision = get_pre(format)) == -1)
		precision = 0;
	while (flags[i])
	{
		if (flags[i] == '0' && !ft_strchr(flags, '-') && !precision)
			zero_flag(arg, num);
		if (flags[i] == '-')
			minos_flag(arg);
		if (flags[i] == '+' && (num > 0))
			plus_flag(arg, precision);
		i++;
	}	
}