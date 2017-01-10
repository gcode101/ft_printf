/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_signs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:31:58 by gcortina          #+#    #+#             */
/*   Updated: 2017/01/10 14:32:00 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	new_temp(const char **temp, int i)
{
	int 		re;
	const char	*str;

	re = 0;
	str = *temp;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '%')
			break ;
		if (str[i] == '%')
		{
			re = 1;
			*temp = *temp + i + 1;
			break ;
		}
		i++;
	}
	return (re);
}

int			percent_signs(const char * restrict str)
{
	int			i;
	int			ct;
	const char	*temp;

	i = 0;
	ct = 0;
	temp = str;
	while (temp[i])
	{
		if (temp[i] == '%' && temp[i + 1] == ' ')
		{
			if (new_temp(&temp, i + 1))
			{
				ct++;
				i = -1;
			}
		}
		if (temp[i] == '%' && temp[i + 1] == '%')
		{
			if (i >= 0)
			{
				ct++;
				temp = temp + i + 2;
				i = -1;
			}
		}
		else if (i == 0 && temp[i] == '%')
			ct++;
		else if (temp[i] == '%' && temp[i - 1] != '%')
			if (i >= 0)
				ct++;
		i++;
	}
	return (ct);
}
