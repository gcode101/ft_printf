/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec_lenflag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:25:38 by gcortina          #+#    #+#             */
/*   Updated: 2016/12/09 10:25:44 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_dec_lenflag(char *len_flag, va_list args)
{

	if (len_flag && ft_strcmp(len_flag, "l") == 0)
		return (ft_itoa_base(va_arg(args, long), 10));
	else if (len_flag && ft_strcmp(len_flag, "ll") == 0)
		return (ft_itoa_base(va_arg(args, long long), 10));
	else if (len_flag && ft_strcmp(len_flag, "j") == 0)
		return (ft_itoa_base(va_arg(args, intmax_t), 10));
	else if (len_flag && ft_strcmp(len_flag, "z") == 0)
		return (ft_itoa_base(va_arg(args, size_t), 10));
	else
		return (ft_itoa_base(va_arg(args, int), 10));
}