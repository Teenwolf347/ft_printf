/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:17:43 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 20:25:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_prec(long int number, t_args *args)
{
	if (number < 0)
	{
		ft_putchar_prec('-', args);
		number = -number;
	}
	if (number < 10)
	{
		ft_putchar_prec(number + 48, args);
		return ;
	}
	ft_putnbr_prec(number / 10, args);
	ft_putchar_prec(number % 10 + 48, args);
}
