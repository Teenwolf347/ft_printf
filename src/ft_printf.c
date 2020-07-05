/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:10:38 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/05 16:57:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_initialization_args(t_args *args)
{
	args->ptr = 1;
	args->conv = 0;
	args->zero = 0;
	args->start = 0;
	args->width = 0;
	args->minus = 0;
	args->length = 0;
	args->result = 0;
	args->ifprec = 0;
	args->precision = 0;
}

static int	ft_printf_continuation(char *format, va_list argptr)
{
	t_args	args;
	int		i;
	int		start;
	int		result;

	i = 0;
	start = 0;
	result = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_printf_write(start, i, format); // Добавить потом
			result = (result + i) - start;
			ft_initialization_args(&args);
			ft_format_handler(format, &i, &args, argptr); // Добавить потом и переменовать
			args.conv != 0 && args.conv != -1 ? i++ : i; // подумать как превести к обычному if
			ft_printf_format(&args, argptr); // Добавить потом и переменовать
			result = result + args.result;
			start = i;
		}
		format[i] != '\0' && format[i] != '%' ? i++ : i; // подумать как превести к обычному if
	}
	ft_printf_write(start, i, format);
	return ((result + i) - start);
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		result;

	va_start(argptr, format);
	result = ft_printf_continuation(format, argptr);
	va_end(argptr);
	return (result);
}
