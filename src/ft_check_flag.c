/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:59:00 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/23 12:59:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_flag(t_args *args, const char *format)
{
	int		i;

	i = 0;
	while (format[++i] != '\0' && args->flag == 0)
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
		{
			args->flag_type = 0;
			args->flag = format[i];
		}
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
				format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
		{
			args->flag_type = 1;
			if (format[i] == 'i')
				args->flag = 'd';
			else
				args->flag = format[i];
		}
		if (args->flag != 0)
			return ((i == 0 && args->flag != 0) ? i + 1 : i);
	}
	return (1);
}
