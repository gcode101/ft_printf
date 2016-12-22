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

	// printf("%s\n", "inside shift_right");
	len = ft_strlen(str);
	i = len - 1;
	// printf("num: %d\n", num);
	// printf("i: %d\n", i);
	// printf("len: %d\n", len);
	// printf("str: {%s}\n", str);
	while (str[i] && str[i] == ' ')
		i--;
	if ((i + num) >= len)
		return (0);
	while (i >= 0)
	{
		// printf("i: %d\n", i);
		str[i + num] = str[i];
		i--;
		// printf("str: {%s}\n", str);
	}
	i = 0;
	while (num--)
		str[i++] = ' ';
	// printf("str: {%s}\n", str);
	return (1);
}
