/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:25:54 by tturnber          #+#    #+#             */
/*   Updated: 2020/05/21 17:09:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_atoi(const char *nptr)
{
	int			atoint;
	int			sign;
	int			pnb;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if ((*nptr == '+') || (*nptr == '-'))
		nptr++;
	atoint = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		pnb = atoint;
		atoint = atoint * 10 - '0' + *nptr++;
		if (pnb != atoint / 10 && (atoint & 0x7FFF))
			return ((sign > 0) ? -1 : 0);
	}
	return (atoint * sign);
}
