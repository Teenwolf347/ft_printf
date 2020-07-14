/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:29:55 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/14 19:19:22 by student          ###   ########.fr       */
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
			ft_putchar_precision('0', args);
		else
			ft_putchar_precision(' ', args);
		WIDTH--;
	}
	ft_putchar_precision(c, args);
	while (WIDTH > 0)
	{
		ft_putchar_precision(' ', args);
		WIDTH--;
	}
}

void				ft_printf_write_string(t_args *args, va_list argptr)
{
	char			*str;

	str = va_arg(argptr, char *);
	if (str == NULL)
		str = NULL;
	LENGTH = ft_strlen(str);
	ft_printf_char_or_string(args);
	while (MINUS == 0 && WIDTH > 0)
	{
		if (ZERO == 1)
			ft_putchar_precision('0', args);
		else
			ft_putchar_precision(' ', args);
		WIDTH--;
	}
	if (WIDTH < 0)
		WIDTH = ((WIDTH * (-1)) - (LENGTH * 2)) - 1;
	while (*str != '\0' && LENGTH > 0)
	{
		ft_putchar_precision(*str++, args);
		LENGTH++;
	}
	while (WIDTH-- > 0)
		ft_putchar_precision(' ', args);
}
