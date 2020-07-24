/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char_or_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:55:46 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 20:17:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_write_str(char *str, int max, int dots)
{
	int		i;

	i = 0;
	if ((dots == 1 && max != 0) || dots == 0)
	{
		i = -1;
		while (str[++i] && (i < max || max == 0))
			ft_putchar_fd(str[i], 1);
	}
	return (i);
}

static int	ft_write_space(int min, int max, int length, char c)
{
	int i;
	int limit;

	i = -1;
	limit = (max < length && max != 0) ? max : length;
	while (++i < min - limit)
		ft_putchar_fd(c, 1);
	return (i);
}

int			ft_write_string(t_args *args, char *str)
{
	int		result;
	int		length;
	int		stop;

	result = 0;
	stop = 0;
	length = ft_strlen(str);
	if (args->max == 0 && args->dots == 1)
		length = 0;
	if (args->type == 1)
	{
		stop = 1;
		result += ft_write_str(str, args->max, args->dots);
	}
	result += ft_write_space(args->min, args->max, length,
			(args->zero == 1) ? '0' : ' ');
	if (stop == 0)
		result += ft_write_str(str, args->max, args->dots);
	return (result);
}

int			ft_write_char(t_args *args, char str)
{
	char	arr[2];
	int		stop;
	int		result;

	if (str != '\0')
	{
		arr[0] = str;
		arr[1] = '\0';
		result = ft_write_string(*&args, arr);
	}
	else
	{
		stop = 0;
		if (args->type == 1 && (stop = 1))
			ft_putchar_fd('\0', 1);
		result = ft_write_space(args->min, args->max, 1, (args->zero == 1) ?
				'0' : ' ');
		if (stop == 0)
			ft_putchar_fd('\0', 1);
		return (result + 1);
	}
	return (result);
}
