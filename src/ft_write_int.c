/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:17:34 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 19:03:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_write_zero(t_args *args, char c, int number, int t)
{
	int		i;
	int		length;
	int		a;
	int		limit;

	i = 0;
	length = (args->max != -1 || number > 0) ? ft_get_long(number) : 0;
	if (t == 1)
		limit = args->max - length;
	else
	{
		length += (number < 0) ? 1 : 0;
		a = (number < 0) ? 1 : 0;
		limit = args->min - ((args->max > length) ? args->max + a : length);
		args->min = 0;
	}
	limit = (limit < 0) ? 0 : limit;
	while (++i <= limit)
		ft_putchar_fd(c, 1);
	return (i - 1);
}

static int	ft_write_d(int number, t_args *args, int length)
{
	int		result;

	result = 0;
	if (number >= 0)
		result += ft_write_zero(*&args, '0', number, 1);
	else
	{
		ft_putchar_fd('-', 1);
		if (args->min > length && args->max == 0)
			args->max = args->min - ((number < 0) ? 1 : 0);
		result += ft_write_zero(*&args, '0', number, 1);
		if (number == INT32_MIN)
			ft_putstr_fd("2147483648", 1);
		else
			ft_putnbr_fd(number * -1, 1);
	}
	return (result);
}

static int	ft_write_int_con(int number, t_args *args, int length, int *printed)
{
	int		result;

	result = 0;
	if (args->type == 1)
	{
		if (args->max > length)
		{
			result += ft_write_d(number, *&args, length);
			*printed = (number < 0) ? 1 : 0;
		}
		if (*printed != 1 && (args->max != -1 || number != 0))
			ft_putnbr_fd(number, 1);
		*printed = 1;
	}
	if (args->zero == 0 || (args->min > args->max && args->max != 0))
		result += ft_write_zero(*&args, ' ', number, 0);
	return (result);
}

int			ft_write_int(t_args *args, int number)
{
	int		result;
	int		length;
	int		printed;

	result = 0;
	printed = 0;
	length = ft_get_long(number) + ((number < 0) ? 1 : 0);
	length = (args->max == -1 && number == 0) ? 0 : length;
	result += ft_write_int_con(number, *&args, length, &printed);
	if (args->zero == 1 && args->dots == 0 && args->type == 0 && printed != 1)
	{
		if (number >= 0)
			result += ft_write_zero(*&args, '0', number, 0);
		result += ft_write_d(number, *&args, length);
		printed = (number < 0) ? 1 : 0;
	}
	if (args->dots != 0 && printed != 1)
	{
		result += ft_write_d(number, *&args, length);
		printed = (number < 0) ? 1 : 0;
	}
	if (printed != 1 && (args->max != -1 || number != 0))
		ft_putnbr_fd(number, 1);
	return (result + length);
}
