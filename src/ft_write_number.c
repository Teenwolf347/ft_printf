/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:04:25 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 14:48:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_zero(t_number *num)
{
	if (num->nbr < 0)
	{
		ft_putchar_fd('-', 1);
		num->nbr = -num->nbr;
	}
}

static void		ft_zero_pointer(t_number *num, t_args *args)
{
	if (num->nbr < 0)
	{
		args->precn++;
		if (args->width < args->precn)
			args->width++;
	}
}

static int		ft_number_pointer(t_number num, t_args args, int type, int cap)
{
	if ((args.zero) && num.nbr > -1 && args.precn < 0)
		args.precn = args.width;
	else if (args.precn < 0 && (args.zero) && num.nbr < 0)
		args.precn = args.width - 1;
	if ((long)num.length <= args.precn)
		ft_zero_pointer(&num, &args);
	if (args.precn < (long)num.length)
		args.precn = num.length;
	if (args.width < args.precn && args.precn > 0)
		args.width = args.precn;
	if (!args.minus)
	{
		ft_printf_putchar(' ', args.width - args.precn);
		ft_zero(&num);
		ft_printf_putchar('0', args.precn - num.length);
		ft_printf_putnbr(num.nbr, 1, type, cap);
	}
	else
	{
		ft_zero(&num);
		ft_printf_putchar('0', args.precn - num.length);
		ft_printf_putnbr(num.nbr, 1, type, cap);
		ft_printf_putchar(' ', args.width - args.precn);
	}
	return (args.width);
}

static int		ft_number_not_pointer(t_number num, t_args args,
		int type, int cap)
{
	char		space;

	if (args.width < 0)
		args.width = -args.width;
	if (args.zero)
	{
		space = '0';
		ft_zero(&num);
	}
	else
		space = ' ';
	if ((long)num.length < args.width)
		args.precn = args.width - num.length;
	if (!args.minus)
	{
		ft_printf_putchar(space, args.precn);
		ft_printf_putnbr(num.nbr, 1, type, cap);
	}
	else
	{
		ft_printf_putnbr(num.nbr, 1, type, cap);
		ft_printf_putchar(space, args.precn);
	}
	return (args.precn + num.length);
}

int				ft_write_number(long number, int type, int cap, t_args args)
{
	t_number	num;

	num.nbr = number;
	num.length = ft_length_number(number, type);
	if (!args.pointer)
		return (ft_number_not_pointer(num, args, type, cap));
	else
	{
		if (!number && !args.precn)
		{
			ft_printf_putchar(' ', args.width);
			return (args.width);
		}
		return (ft_number_pointer(num, args, type, cap));
	}
}
