/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 13:25:54 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/20 12:13:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_atoi(const char *str)
{
	long res;
	long sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
			*str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 + (*str -
						'0')) && sign == 1)
			return (-1);
		else if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 +
					(*str - '0')) && sign == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
