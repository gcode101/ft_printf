/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchr_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:26:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/12 16:26:48 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchr_len(wchar_t chr)
{
	int chr_len;

	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	return (chr_len);
}
