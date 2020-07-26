/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 21:20:28 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/25 21:44:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_printf_format_con(const char **format, va_list argptr)
{
	int			length;
	int			width;
	const char	*str;

	str = *format;
	length = 0;
	if (**format == '*')
	{
		*format = *format + 1;
		return (va_arg(argptr, int));
	}
	else
	{
		while (!(ft_memchr("%cspdiuxX.", *str, 11)))
		{
			length++;
			str++;
		}
		str = str - length;
		width = ft_atoi(str);
		*format = *format + length;
		return (width);
	}
}

static void		ft_printf_min_zero(const char **format, t_args **args)
{
	t_args *args_2;

	args_2 = *args;
	if (**format == '0')
	{
		args_2->zero = 1;
		(*format)++;
	}
	else if (**format == '-')
	{
		args_2->minus = 1;
		(*format)++;
	}
}

const char		*ft_printf_format(va_list argptr,
		const char *format, t_args *args)
{
	if (*format == '\0')
		return (format);
	while (*format == '0' || *format == '-')
		ft_printf_min_zero(&format, &args);
	args->width = ft_printf_format_con(&format, argptr);
	if (args->width < 0)
	{
		args->width *= -1;
		args->minus = 1;
	}
	if (*format == '.' && format++)
	{
		args->pointer = 1;
		args->precn = ft_printf_format_con(&format, argptr);
	}
	if (*format)
		args->type = *format++;
	return (format);
}
