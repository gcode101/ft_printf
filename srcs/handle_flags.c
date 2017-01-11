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

static void	plus_flag_helper(char **arg, int len)
{
	char	*temp;
	char	*str;
	int		i;

	str = *arg;
	i = 0;
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

static void	plus_flag(char **arg, int precision)
{
	int		i;
	int		len;
	char	*str;

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
		plus_flag_helper(arg, len);
}

void		handle_flags(char *format, char *flags, char **arg, int num)
{
	int		i;
	int		precision;
	int		space;

	i = 0;
	space = 0;
	if (ft_strchr(flags, ' '))
		space = 1;
	if ((precision = get_pre(format)) == -2)
		precision = 0;
	while (flags[i])
	{
		if (flags[i] == '0' && !ft_strchr(flags, '-') &&
			!ft_strchr(format, '.'))
			zero_flag(arg, num, space);
		if (flags[i] == '-')
			minos_flag(arg);
		if (flags[i] == '+' && (num > 0))
			plus_flag(arg, precision);
		if (flags[i] == ' ' && (num > 0) && !ft_strchr(flags, '+'))
			space_flag(arg, precision);
		i++;
	}
}
