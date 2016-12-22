/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:33:05 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/15 13:33:07 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(char c)
{
	char	*valid_chrs;

	valid_chrs = "sSpdDioOuUxXcChljz#0-+. ";
	if (ft_strchr(valid_chrs, c))
		return (1);
	return (0);
}
