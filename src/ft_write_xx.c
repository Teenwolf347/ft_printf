/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:15:00 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 22:16:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_get_x_len(unsigned int number)
{
	unsigned int	b;
	int				result;

	result = 0;
	if (number != 0)
	{
		b = number % 16;
		result += ft_get_x_len(number / 16);
	}
	return (result + 1);
}

static int			ft_write_x_zero(t_args *args, char c,
		unsigned int number, int t)
{
	int				i;
	int				length;
	int				limit;

	i = 0;
	length = (args->max != -1 || number > 0) ? ft_get_x_len(number) - 1 : 0;
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

static int			ft_write_x_con_2(unsigned int number, t_args *args,
		int t, int length)
{
	unsigned int	b;
	int				result;

	result = 0;
	if (number != 0)
	{
		b = number % 16;
		result += ft_write_x_con_2(number / 16, *&args, t, length);
		if (b > 9)
			ft_putchar_fd(b + ((t == 1) ? (int)'A' : (int)'a') - 10, 1);
		else
			ft_putnbr_fd(b, 1);
	}
	return (result + 1);
}

static int			ft_write_x_con(unsigned int number, t_args *args,
		int t, int *printed)
{
	int				result;
	int				length;

	length = ft_get_x_len(number) - ((number != 0) ? 1 : 0);
	length = (args->max == -1 && number == 0) ? 0 : length;
	result = 0;
	if (args->type == 1)
	{
		if (args->max > length)
			result += ft_write_x_zero(*&args, '0', number, 1);
		if ((args->max != -1) || number > 0)
		{
			if (number == 0)
				ft_putnbr_fd(0, 1);
			ft_write_x_con_2(number, *&args, t, length);
		}
		*printed = 1;
	}
	if (args->zero == 0 || (args->min > args->max && args->max != 0))
		result += ft_write_x_zero(*&args, ' ', number, 0);
	return (result);
}

int					ft_write_x(unsigned int number, t_args *args, int t)
{
	int				result;
	int				length;
	int				printed;

	result = 0;
	printed = 0;
	length = ft_get_x_len(number) - ((number != 0) ? 1 : 0);
	length = (args->max == -1 && number == 0) ? 0 : length;
	result += ft_write_x_con(number, *&args, t, &printed);
	if (args->zero == 1 && args->dots == 0 && args->type == 0 && printed != 1)
	{
		if (number > 0 || number == 0)
			result += ft_write_x_zero(*&args, '0', number, 0);
		result += ft_write_x_zero(*&args, '0', number, 1);
	}
	if (args->dots != 0 && printed != 1)
		result += ft_write_x_zero(*&args, '0', number, 1);
	if (printed != 1 && (args->max != -1 || number > 0))
	{
		if (number == 0)
			ft_putnbr_fd(0, 1);
		ft_write_x_con_2(number, *&args, t, length);
	}
	return (result + length);
}
