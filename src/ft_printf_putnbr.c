/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:44:00 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 14:51:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_length_number(long number, int type)
{
	int				length;

	length = 0;
	while (number > type - 1 || number < -(type - 1))
	{
		length++;
		number /= type;
	}
	length++;
	if (number < 0)
		length++;
	return (length);
}

void				ft_printf_putnbr(long number, int fd, size_t type, int cap)
{
	char			symb;
	unsigned long	m;
	char			cp;

	cp = cap ? 'A' : 'a';
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	m = (unsigned long)number;
	if (m >= type)
	{
		ft_printf_putnbr(m / type, fd, type, cap);
		symb = (m % type) + (m % type > 9 ? cp - 10 : '0');
		write(fd, &symb, 1);
	}
	if ((m > 0 || m == 0) && m <= type - 1)
	{
		symb = m + (m % type > 9 ? cp - 10 : '0');
		write(fd, &symb, 1);
	}
}
