/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:49:56 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 18:22:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_write_format(va_list argptr, int result, t_args args)
{
	if (args.type == 's')
		result += ft_write_string(va_arg(argptr, char *), args);
	else if (args.type == 'c')
		result += ft_write_char((char)va_arg(argptr, int), args);
	else if (args.type == '%')
		result += ft_write_char('%', args);
	else if (args.type == 'd' || args.type == 'i')
		result += ft_write_number((long)va_arg(argptr, int), 10, 0, args);
	else if (args.type == 'u')
		result += ft_write_number((long)va_arg(argptr, unsigned int),
				10, 0, args);
	else if (args.type == 'x')
		result += ft_write_number((long)va_arg(argptr, unsigned int),
				16, 0, args);
	else if (args.type == 'X')
		result += ft_write_number((long)va_arg(argptr, unsigned int),
				16, 1, args);
	else if (args.type == 'p')
		result += ft_write_pointer(va_arg(argptr, long), 16, args);
	return (result);
}
