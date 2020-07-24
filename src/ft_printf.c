/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:30:46 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/25 00:03:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_initialization(t_args *args)
{
	args->max = 0;
	args->min = 0;
	args->type = 0;
	args->flag = 0;
	args->zero = 0;
	args->dots = 0;
	args->error = 0;
	args->length = 0;
	args->flag_type = 0;
	return (1);
}

static int	ft_clean_args(t_args *args)
{
	if (args)
	{
		args->max = 0;
		args->min = 0;
		args->type = 0;
		args->flag = 0;
		args->zero = 0;
		args->dots = 0;
		args->flag_type = 0;
	}
	return (-1);
}

static int	ft_space(const char *format, int i, t_args *args)
{
	if (format[i + 1] == ' ')
	{
		ft_putchar_fd(' ', 1);
		args->length++;
		i++;
	}
	return (i);
}

static int	ft_printf_con(t_args *args, int *i, const char *f, va_list *argptr)
{
	int		ch;

	ch = ft_check_arguments(*&args, (char *)f, *i, *&argptr);
	if (ch == -1)
		return (-1);
	*i = *i + ch;
	ft_write_format(*&args, *&argptr);
	ft_clean_args(*&args);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list argptr;
	t_args	args;
	int		i;

	va_start(argptr, format);
	if (!(ft_initialization(&args)))
		return (-1);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = ft_space(format, i, &args);
			if (ft_printf_con(&args, &i, format, &argptr) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			args.length++;
			i++;
		}
	}
	va_end(argptr);
	return (args.length);
}
