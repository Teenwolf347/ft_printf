/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:10:38 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/12 11:41:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_printf_write(int start, int i, char *format)
{
	while (format[start] != '\0' && start < i)
	{
		write(1, &format[start], 1);
		start++;
	}
}

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
			ft_printf_write(start, i, format);
			result = (result + i) - start;
			ft_initialization_args(&args);
			ft_format_check(format, &i, &args, argptr);
			args.conv != 0 && args.conv != -1 ? i++ : i;
			ft_printf_write_format(&args, argptr);
			result = result + args.result;
			start = i;
		}
		format[i] != '\0' && format[i] != '%' ? i++ : i;
	}
	ft_printf_write(start, i, format);
	return ((result + i) - start);
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		result;

	va_start(argptr, format);
	result = ft_printf_continuation((char *)format, argptr);
	va_end(argptr);
	return (result);
}
