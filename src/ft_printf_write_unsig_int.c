/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_unsig_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:24:17 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/16 19:46:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					ft_check_unsigned_int(t_args *args)
{
	if (PRECISION < 0)
	{
		MINUS = 1;
		WIDTH = PRECISION * (-1);
	}
	PRECISION = PRECISION - LENGTH;
	if (PRECISION > 0)
		WIDTH = WIDTH - PRECISION + LENGTH;
	else
		WIDTH = WIDTH - LENGTH;
	if (IFPREC == 1)
		ZERO = 0;
}

void						ft_printf_write_unsig_int(t_args *args, va_list a)
{
	unsigned long long int	number;
	char					*str;

	number = (long long int)NULL;
	if (CONV == 'u' || CONV == 'x' || CONV == 'X')
		number = (unsigned int)va_arg(a, void*);
	str = ft_convert(args, number);
	LENGTH = ft_strlen(str);
	ft_check_unsigned_int(args);
	if (MINUS == 0)
		while (WIDTH-- > 0)
		{
			if (ZERO == 1)
				ft_putchar_prec('0', args);
			else
				ft_putchar_prec(' ', args);
		}
	while (PRECISION-- > 0)
		ft_putchar_prec('0', args);
	ft_putstr_prec(str, args);
	WIDTH = WIDTH < 0 ? WIDTH * (-1) - (2 * LENGTH + 1) : WIDTH;
	while (WIDTH-- > 0)
		ft_putchar_prec(' ', args);
	free(str);
}
