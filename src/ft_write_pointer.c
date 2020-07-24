/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:37:23 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 23:11:40 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				ft_get_pointer_len(unsigned long long number)
{
	unsigned long long	b;
	int					result;

	result = 0;
	if (number != 0)
	{
		b = number % 16;
		result += ft_get_pointer_len(number / 16);
	}
	return (result + 1);
}

static void				ft_write_pointer_con(unsigned long long number,
		t_args *args)
{
	unsigned int		b;

	if (number != 0)
	{
		b = number % 16;
		ft_write_pointer_con(number / 16, *&args);
		if (b > 9)
			ft_putchar_fd(b + (int)'a' - 10, 1);
		else
			ft_putnbr_fd(b, 1);
	}
}

static int				ft_write_pointer_zero(t_args *args, char c,
		unsigned long long number, int t)
{
	int					i;
	int					length;
	int					limit;

	i = 0;
	length = (args->max != -1 || number > 0) ?
		ft_get_pointer_len(number) + 1 : 0;
	length += (args->max == -1 && number == 0) ? 2 : 0;
	length += (number == 0 && args->max != -1) ? 1 : 0;
	if (t == 1)
		limit = args->max - (length - 2);
	else
	{
		limit = args->min - ((args->max > length) ? args->max : length);
		args->min = 0;
	}
	limit = (limit < 0) ? 0 : limit;
	while (++i <= limit)
		ft_putchar_fd(c, 1);
	return (i - 1);
}

int						ft_write_pointer(unsigned long long number,
		t_args *args)
{
	int		length;
	int		result;

	result = 0;
	length = (number == 0 && (args->max != -1 || number > 0))
		? 1 : ft_get_pointer_len(number) - 1;
	if (args->type == 0)
		result += ft_write_pointer_zero(*&args, ' ', number, 0);
	ft_putstr_fd("0x", 1);
	result += ft_write_pointer_zero(*&args, '0', number, 1);
	if ((number == 0 && args->max >= 0) && (args->max != -1 || number > 0))
		ft_putnbr_unsigned_int(0);
	ft_write_pointer_con(number, *&args);
	if (args->type == 1)
		result += ft_write_pointer_zero(*&args, ' ', number, 0);
	return (result + length + 2);
}
