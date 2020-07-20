/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:28:28 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/19 19:08:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_write_precision(t_args *args)
{
	int	width;

	width = 0;
	while (MINUS == 0 && width++ < WIDTH - 1)
		ZERO == 1 ? ft_putchar_prec('0', args) : ft_putchar_prec(' ', args);
	if (CONV != -1)
		ft_putchar_prec('%', args);
	while (width++ < WIDTH - 1)
		ZERO == 1 ? ft_putchar_prec('0', args) : ft_putchar_prec(' ', args);
}
