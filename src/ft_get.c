/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:35:35 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/23 13:45:23 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_long(int i)
{
	int			result;

	result = 0;
	if (i == 0)
		result = 1;
	while (i != 0)
	{
		result++;
		i /= 10;
	}
	return (result);
}

void	ft_get_int(int d, t_args *args)
{
	if (d >= 0)
	{
		if (d == 0 && args->flag_type == 1)
			args->max = -1;
		else
			args->max = d;
	}
	else if (d < 0 && args->flag_type == 0)
	{
		args->type = 1;
		if (args->flag_type == 1)
			d = (d != INT32_MIN) ? d * -1 : INT32_MAX;
		else
			d = INT32_MAX;
		args->max = d;
	}
	else if (d < 0 && args->flag_type == 1)
		args->max = -2;
}
