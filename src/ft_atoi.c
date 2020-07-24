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

int					ft_atoi(const char *str)
{
	int				i;
	int				negativ;
	unsigned long	number;

	i = 0;
	number = 0;
	negativ = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negativ = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = ((long)(number * 10) + (str[i++] - '0'));
		if (number > 9223372036854775807 && negativ == 1)
			return (-1);
		if (number > 9223372036854775807 && negativ == -1)
			return (0);
	}
	return (number * negativ);
}
