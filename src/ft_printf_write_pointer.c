/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:31:35 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 19:17:13 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					ft_printf_check_pointer(t_args *args)
{
	if (PRECISION < 0)
	{
		MINUS = 1;
		WIDTH = PRECISION * (-1);
	}
	PRECISION = PRECISION - LENGTH;
	if (PRECISION > 0)
		WIDTH = WIDTH - (PRECISION + LENGTH + 2);
	else
		WIDTH = WIDTH - (LENGTH + 2);
	if (IFPREC == 1)
		ZERO = 0;
}

void						ft_printf_write_pointer(t_args *args, va_list argp)
{
	unsigned long long int	number;
	char					*str;

	number = va_arg(argp, unsigned long long int);
	str = ft_convert(args, number);
	LENGTH = ft_strlen(str);
	ft_printf_check_pointer(args);
	if (MINUS <= 0 && WIDTH <= 0 && PRECISION <= 0 && IFPREC <= 0 && ZERO <= 0)
	{
		ft_putstr_prec("0x", args);
		ft_putstr_prec(str, args);
		return ;
	}
	if (ZERO == 0)
		ft_putstr_prec("0x", args);
	while (MINUS == 0 && WIDTH-- > 0)
		ZERO == 1 ? ft_putchar_prec('0', args) : ft_putchar_prec(' ', args);
	ft_putstr_prec("0x", args);
	while (PRECISION-- > 0)
		ft_putchar_prec('0', args);
	ft_putstr_prec(str, args);
	while (WIDTH-- > 0)
		ft_putchar_prec(' ', args);
	free(str);
}
