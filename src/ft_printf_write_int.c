/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:20:50 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 18:18:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_printf_check_int(t_args *args, long int number)
{
	char	*length;

	length = ft_itoa(number);
	if (number == 0 && IFPREC == 1)
		LENGTH = 0;
	else
		LENGTH = ft_strlen(length);
	if (number < 0)
		LENGTH--;
	if (WIDTH < 0)
		WIDTH = WIDTH * (-1);
	if (PRECISION < 0 && START == 0)
		PRECISION = PRECISION * (-1);
	PRECISION = PRECISION - LENGTH;
	if (PRECISION > 0)
		WIDTH = WIDTH - (PRECISION + LENGTH);
	else
		WIDTH = WIDTH - LENGTH;
	if (number < 0)
		WIDTH = WIDTH - 1;
	if (IFPREC == 1 && START == 0)
		ZERO = 0;
}

void			ft_printf_write_int(t_args *args, va_list argptr)
{
	long int number;

	number = (long long int)NULL;
	if (CONV == 'd' || CONV == 'i')
		number = (int)va_arg(argptr, void*);
	ft_printf_check_int(args, number);
	if (number < 0 && ZERO == 1)
	{
		ft_putchar_prec('-', args);
		number = number * (-1);
	}
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putchar_prec('0', args) : ft_putchar_prec(' ', args);
	if (number < 0 && PRECISION > 0)
	{
		ft_putchar_prec('-', args);
		number = number * (-1);
	}
	while (PRECISION-- > 0)
		ft_putchar_prec('0', args);
	if (LENGTH > 0 || (number == 0 && IFPREC == 0))
		ft_putnbr_prec(number, args);
	while (WIDTH-- > 0)
		ft_putchar_prec(' ', args);
}
