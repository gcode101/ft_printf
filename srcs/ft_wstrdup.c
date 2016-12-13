/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:42:58 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/07 13:42:59 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrdup(wchar_t *src)
{
	wchar_t	*str;
	wchar_t	*p;
	int		len;

	len = 0;
	while (src[len])
		len++;
	if (!(str = malloc(len + 1)))
		return (NULL);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
