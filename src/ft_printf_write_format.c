/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:13:01 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/13 19:25:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_write_format(t_args *args, va_list argptr)
{
	if (CONV == '%' || CONV == -1)
		ft_printf_write_precision(args);
	else if (CONV == 's')
		ft_printf_write_string(args, argptr);
	else if (CONV == 'c')
		ft_printf_write_char(args, argptr);
	else if (CONV == 'p')
		ft_printf_write_pointer(args, argptr);
	else if (CONV == 'd' || CONV == 'i')
		ft_printf_write_int(args, argptr);
	else if (CONV == 'u' || CONV == 'x' || CONV == 'X')
		ft_printf_write_unsigned_int(args, argptr); // Потом
}
