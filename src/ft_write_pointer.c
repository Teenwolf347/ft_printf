/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:52:32 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 16:24:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_pointer_null(t_args args)
{
	if (!args.width)
		args.width = 2;
	if (args.precn < 0)
		args.precn = 1;
	if (args.width < args.precn + 2)
		args.width = args.precn + 2;
	if (args.minus == 1)
	{
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putchar('0', args.precn);
		ft_printf_putchar(' ', args.width - args.precn - 2);
	}
	else
	{
		ft_printf_putchar(' ', args.width - args.precn - 2);
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putchar('0', args.precn);
	}
	return (args.width);
}

static int		ft_pointer_pointer(t_number num, t_args args, int type)
{
	if (args.precn < (long)num.length || args.precn < 0)
		args.precn = num.length;
	if (args.width > args.precn)
		args.width -= 2;
	if (args.width < args.precn)
		args.width = args.precn;
	if (!args.minus)
	{
		ft_printf_putchar(' ', args.width - args.precn);
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putchar('0', args.precn - num.length);
		ft_printf_putnbr(num.nbr, 1, type, 0);
	}
	else
	{
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putchar('0', args.precn - num.length);
		ft_printf_putnbr(num.nbr, 1, type, 0);
		ft_printf_putchar(' ', args.width - args.precn);
	}
	return (args.width + 2);
}

static int		ft_pointer_not_pointer(t_number num, t_args args, int type)
{
	char		space;

	if (args.zero)
		space = '0';
	else
		space = ' ';
	if ((long)num.length + 2 < args.width)
		args.precn = args.width - num.length - 2;
	if (!args.minus)
	{
		ft_printf_putchar(space, args.precn);
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putnbr(num.nbr, 1, type, 0);
	}
	else
	{
		ft_putstr_fd("0x", 1, 2);
		ft_printf_putnbr(num.nbr, 1, type, 0);
		ft_printf_putchar(space, args.precn);
	}
	return (args.precn + num.length + 2);
}

int				ft_write_pointer(long number, int type, t_args args)
{
	t_number	num;

	num.nbr = number;
	num.length = ft_length_number(number, type);
	if (!args.pointer)
		return (ft_pointer_not_pointer(num, args, type));
	else
	{
		if (number == 0)
			return (ft_pointer_null(args));
		return (ft_pointer_pointer(num, args, type));
	}
}
