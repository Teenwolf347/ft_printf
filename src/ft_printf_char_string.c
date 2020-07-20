/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:29:55 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/20 12:15:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			ft_printf_char_or_string(t_args *args)
{
	if (PRECISION < 0)
		ZERO = 0;
	if (PRECISION < LENGTH && IFPREC == 1 && PRECISION >= 0)
		LENGTH = PRECISION;
	if (WIDTH < 0 && CONV == 'c')
		WIDTH = WIDTH * (-1);
	if (PRECISION < 0 && IFPREC == 0)
		WIDTH = PRECISION * (-1);
	else
		WIDTH = WIDTH - LENGTH;
	if (PRECISION < 0 && CONV == 'c')
	{
		WIDTH = (PRECISION * (-1)) - 1;
		MINUS = 1;
	}
	if (IFPREC == 1 && PRECISION == 0 && CONV == 'c')
		WIDTH--;
}

void				ft_printf_write_char(t_args *args, va_list argptr)
{
	unsigned char	c;

	c = (unsigned char)va_arg(argptr, int);
	LENGTH = 1;
	ft_printf_char_or_string(args);
	while (MINUS == 0 && WIDTH > 0)
	{
		if (ZERO == 1)
			ft_putchar_prec('0', args);
		else
			ft_putchar_prec(' ', args);
		WIDTH--;
	}
	ft_putchar_prec(c, args);
	while (WIDTH > 0)
	{
		ft_putchar_prec(' ', args);
		WIDTH--;
	}
}

void				ft_printf_write_string(t_args *args, va_list argptr)
{
	char	*str;

	str = va_arg(argptr, char *);
	if (str == NULL)
		str = "(null)";
	LENGTH = ft_strlen(str);
	ft_printf_char_or_string(args);
	while (MINUS == 0 && WIDTH-- > 0)
	{
		if (ZERO == 1)
			ft_putchar_prec('0', args);
		else
			ft_putchar_prec(' ', args);
	}
	if (WIDTH < 0)
		WIDTH = (WIDTH * (-1)) - (2 * LENGTH) - 1;
	while (LENGTH-- > 0 && *str != '\0')
		ft_putchar_prec(*str++, args);
	while (WIDTH-- > 0)
		ft_putchar_prec(' ', args);
}
