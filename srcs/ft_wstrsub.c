/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:10:31 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 12:10:32 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t	*res;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(wchar_t) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = '\0';
	return (res);
}
