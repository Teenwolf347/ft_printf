/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:42:45 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/12 19:03:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_check_flag(char *format, int *i, t_args *args)
{
	while (format[*i] != '\0' && (format[*i] == '0'
				|| format[*i] == '-'))
	{
		if (format[*i] == '-')
		{
			MINUS = 1;
			ZERO = 0;
		}
		if (format[*i] == '0' && MINUS == 0)
			ZERO = 1;
		*i += 1;
	}
}

static void		ft_check_width(char *f, int *i, t_args *args, va_list argptr)
{
	while (f[*i] != '\0' && (f[*i] == '*' || (f[*i] >= '0' && f[*i] <= '9')))
	{
		if (f[*i] == '*')
		{
			WIDTH = va_arg(argptr, int);
			*i += 1;
		}
		else
		{
			while (f[*i] >= '0' && f[*i] <= '9')
			{
				WIDTH = WIDTH * 10 + f[*i] - '0';
				*i += 1;
			}
		}
	}
}

static void		ft_check_precision(char *f, int *i, t_args *args, va_list arg)
{
	char *ptr;

	if (f[*i] != '.')
		return ;
	ptr = f;
	PRECISION = 0;
	*i += 1;
	IFPREC = 1;
	while (f[*i] != '\0' && (f[*i] == '-' || f[*i] == '*'
				|| (f[*i] >= '0' && f[*i] <= '9')))
	{
		if (f[*i] == '*')
		{
			START = 1;
			PRECISION = va_arg(arg, int);
			*i += 1;
		}
		else
		{
			ptr += *i;
			PRECISION = ft_atoi(ptr);
			while ((f[*i] && (f[*i] >= '0' && f[*i] <= '9')) || f[*i] == '-')
				*i += 1;
		}
	}
}

static void		ft_check_conv(char conv, t_args *args)
{
	if (conv == 'i' || conv == 'd' || conv == 'c' || conv == 's' || conv == 'p'
			|| conv == 'u' || conv == 'x' || conv == 'X' || conv == '%')
		CONV = conv;
	else
		CONV = -1;
}

void			ft_format_check(char *f, int *i, t_args *args, va_list argptr)
{
	*i += 1;
	while (f[*i] != '\0' && (f[*i] == '.' || f[*i] == '-'
				|| f[*i] == '0' || f[*i] == '*'
				|| (f[*i] >= '0' && f[*i] <= '9')))
	{
		ft_check_flag(f, i, args);
		ft_check_width(f, i, args, argptr);
		ft_check_precision(f, i, args, argptr);
	}
	ft_check_conv(f[*i], args);
}
