/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:51:03 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 22:04:20 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_write_format_con(t_args *args, va_list *argptr)
{
	if (args->flag)
	{
		if (args->flag == 'p')
			args->length += ft_write_pointer(va_arg(*argptr,
						unsigned long long), *&args);
		else if (args->flag == 'x' || args->flag == 'X')
		{
			if (args->flag == 'X')
				args->length += ft_write_x(va_arg(*argptr, unsigned int),
						*&args, 1);
			else
				args->length += ft_write_x(va_arg(*argptr, unsigned int),
						*&args, 0);
		}
	}
}

void		ft_write_format(t_args *args, va_list *argptr)
{
	char	*str;

	if (args->flag)
	{
		if (args->flag == 'd')
			args->length += ft_write_int(*&args, va_arg(*argptr, int));
		else if (args->flag == 'u')
			args->length += ft_write_unsigned_int(va_arg(*argptr,
						unsigned int), *&args);
		else if (args->flag == '%')
			args->length += ft_write_char(*&args, '%');
		else if (args->flag == 'c')
			args->length += ft_write_char(*&args, va_arg(*argptr, int));
		else if (args->flag == 's')
		{
			str = va_arg(*argptr, char *);
			if (str == NULL)
				str = "(null)";
			args->length += ft_write_string(*&args, str);
		}
		else
			ft_write_format_con(*&args, *&argptr);
	}
}
