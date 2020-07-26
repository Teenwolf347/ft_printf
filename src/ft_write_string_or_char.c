/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string_or_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:34:24 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 14:03:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_printf_putchar(int c, int length)
{
	while (length != 0)
	{
		write(1, &c, 1);
		length--;
	}
}

static int		ft_string_pointer(t_string string, t_args args)
{
	if ((long)string.length < args.precn || args.precn < 0)
		args.precn = string.length;
	if (args.width < args.precn)
		args.width = args.precn;
	if (!args.minus)
	{
		ft_printf_putchar(' ', args.width - args.precn);
		ft_putstr_fd(string.str, 1, args.precn);
	}
	else
	{
		ft_putstr_fd(string.str, 1, args.precn);
		ft_printf_putchar(' ', args.width - args.precn);
	}
	return (args.width);
}

static int		ft_string_not_pointer(t_string string, t_args args)
{
	char		space;

	if (args.zero)
		space = '0';
	else
		space = ' ';
	if ((long)string.length < args.width)
		args.precn = args.width - string.length;
	if (!args.minus)
	{
		ft_printf_putchar(space, args.precn);
		ft_putstr_fd(string.str, 1, string.length);
	}
	else
	{
		ft_putstr_fd(string.str, 1, string.length);
		ft_printf_putchar(space, args.precn);
	}
	return (args.precn + string.length);
}

int				ft_write_string(char *str, t_args args)
{
	t_string	string;

	string.str = str;
	if (string.str == NULL)
		string.str = "(null)";
	string.length = ft_strlen(string.str);
	if (args.pointer)
		return (ft_string_pointer(string, args));
	else
		return (ft_string_not_pointer(string, args));
}

int				ft_write_char(char c, t_args args)
{
	char		space;

	if (args.zero)
		space = '0';
	else
		space = ' ';
	if (!(args.width))
		args.width = 1;
	if (args.minus == 1)
	{
		ft_putchar_fd(c, 1);
		ft_printf_putchar(space, args.width - 1);
	}
	else
	{
		ft_printf_putchar(space, args.width - 1);
		ft_putchar_fd(c, 1);
	}
	return (args.width);
}
