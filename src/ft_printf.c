/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:38:31 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 18:44:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_initialization(t_args *args)
{
	args->type = 0;
	args->zero = 0;
	args->width = 0;
	args->minus = 0;
	args->pointer = 0;
	args->precn = 0;
}

int			ft_printf(const char *format, ...)
{
	int		result;
	va_list	argptr;
	t_args	args;

	if (!format)
		return (-1);
	va_start(argptr, format);
	result = 0;
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			ft_putchar_fd(*(format++), 1);
			result++;
		}
		ft_initialization(&args);
		format = (*format != '\0') ?
			ft_printf_format(argptr, ++format, &args) : format;
		if (args.zero && args.minus)
			args.zero = 0;
		result = ft_write_format(argptr, result, args);
	}
	va_end(argptr);
	return (result);
}
