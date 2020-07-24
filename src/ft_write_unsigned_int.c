/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:09:02 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 22:48:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_unsigned_number(unsigned int i)
{
	int		result;

	result = 0;
	while (i > 0)
	{
		i /= 10;
		result++;
	}
	return (result);
}

void		ft_putnbr_unsigned_int(unsigned int number)
{
	int		b;

	if (number <= 10)
		ft_putnbr_fd(number, 1);
	else
	{
		b = number % 10;
		number /= 10;
		ft_putnbr_fd(number, 1);
		ft_putnbr_unsigned_int(b);
	}
}

static int	ft_write_unsigned_zero(t_args *args, char c,
		unsigned int number, int t)
{
	int		i;
	int		length;
	int		limit;

	i = 0;
	length = (args->max != -1 || number > 0) ?
		ft_get_unsigned_number(number) : 0;
	length += (number == 0 && (args->max != -1 || number > 0)) ? 1 : 0;
	if (t == 1)
		limit = args->max - length;
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

static int	ft_write_unsigned_int_con(unsigned int number, t_args *args,
		int length, int *printed)
{
	int		result;

	result = 0;
	if (args->type == 1)
	{
		if (args->max > length)
			result += ft_write_unsigned_zero(*&args, '0', number, 1);
		if (args->max != -1 || number > 0)
			ft_putnbr_unsigned_int(number);
		*printed = 1;
	}
	if (args->zero == 0 || (args->min > args->max && args->max != 0))
		result += ft_write_unsigned_zero(*&args, ' ', number, 0);
	return (result);
}

int			ft_write_unsigned_int(unsigned int number, t_args *args)
{
	int		result;
	int		length;
	int		printed;

	result = 0;
	printed = 0;
	length = ft_get_unsigned_number(number) + ((number == 0) ? 1 : 0);
	length = (args->max == -1 && number == 0) ? 0 : length;
	result += ft_write_unsigned_int_con(number, *&args, length, &printed);
	if (args->zero == 1 && args->dots == 0 && args->type == 0 && printed != 1)
	{
		if (number > 0 || number == 0)
			result += ft_write_unsigned_zero(*&args, '0', number, 0);
		result += ft_write_unsigned_zero(*&args, '0', number, 1);
	}
	if (args->dots != 0 && printed != 1)
		result += ft_write_unsigned_zero(*&args, '0', number, 1);
	if (printed != 1 && (args->max != -1 || number > 0))
		ft_putnbr_unsigned_int(number);
	return (result + length);
}
