/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:35:36 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 13:35:38 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_wflag(wchar_t **arg)
{
	int		i;
	wchar_t	*str;

	i = 0;
	str = *arg;
	while (str[i] == ' ')
		str[i++] = '0';
}

static void	minos_wflag(wchar_t **arg)
{
	int		i;
	int		j;
	wchar_t	*str;
	wchar_t	*temp;

	str = *arg;
	i = 0;
	j = 0;
	if ((temp = ft_wstrdup(str)))
	{
		while (temp[i] == ' ')
			i++;
		while (temp[i])
			str[j++] = temp[i++];
		while (str[j])
			str[j++] = ' ';
		free(temp);
	}
}

void		handle_wflags(char *flags, wchar_t **arg)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '0' && !ft_strchr(flags, '-'))
			zero_wflag(arg);
		if (flags[i] == '-')
			minos_wflag(arg);
		i++;
	}
}
