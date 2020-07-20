/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_unsig_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:24:17 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/20 12:15:20 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					ft_check_unsigned_int(t_args *args)
{
	MINUS = PRECISION < 0 ? 1 : MINUS;
	WIDTH = (PRECISION < 0) ? PRECISION * -1 : WIDTH;
	PRECISION -= LENGTH;
	WIDTH -= PRECISION > 0 ? PRECISION + LENGTH : LENGTH;
	if (IFPREC == 1)
		ZERO = 0;
}

void						ft_printf_write_unsig_int(t_args *args, va_list a)
{
	unsigned long long int	number;
	char					*str;

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
	while (WIDTH-- > 0)
		ft_putchar_prec(' ', args);
	free(str);
}
