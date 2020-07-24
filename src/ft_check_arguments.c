/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:14:15 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/23 13:57:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_min_max(t_args *args, int dots, char *str, int i)
{
	int		result;
	char	*str2;

	result = i;
	while (ft_isdigit(str[result]))
		result++;
	if (!(str2 = ft_substr(str, i, result)))
		return (-1);
	result = 0;
	if (ft_isdigit(*str2))
	{
		if (dots == 1)
		{
			result = ft_atoi(str2);
			args->max = (args->flag_type == 1 && result == 0) ? -1 : result;
			result = ft_get_long(args->max);
		}
		else
		{
			args->min = ft_atoi(str2);
			result = ft_get_long(args->min);
		}
	}
	free(str2);
	return (result);
}

static int	ft_get_min_max_argptr(t_args *args, int dots, va_list *argptr)
{
	int		d;

	d = va_arg(*argptr, int);
	if (dots == 1)
		ft_get_int(d, *&args);
	if (dots == 0)
	{
		if (d < 0 && (args->type = 1))
			d *= -1;
		args->min = d;
	}
	return (1);
}

static void	ft_arguments_manager_con(char *s, t_args *args, int *i, va_list *a)
{
	int		st;
	int		str_i;

	st = 0;
	str_i = 0;
	if (s[*i] == '*')
	{
		st = 1;
		*i += ft_get_min_max_argptr(*&args, args->dots, *&a);
	}
	else if (ft_isdigit(s[*i]))
	{
		st = 1;
		str_i = ft_get_min_max(*&args, args->dots, s, *i);
		if (str_i == -1)
		{
			args->error = 1;
			return ;
		}
		*i += str_i;
	}
	else
		*i += 1;
}

static void	ft_arguments_manager(char *str, t_args *args, va_list *argptr)
{
	int i;
	int dots;

	i = 0;
	dots = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (args->type = 1))
			i++;
		else if (str[i] == '.' && dots != 1)
		{
			dots = 1;
			args->dots = 1;
			i++;
		}
		else if (str[i] == '0' &&
				((args->min + args->max + args->type + args->dots) == 0))
		{
			args->zero = 1;
			i++;
		}
		else
			ft_arguments_manager_con(str, *&args, &i, *&argptr);
	}
}

int			ft_check_arguments(t_args *args, char *format, int st, va_list *arg)
{
	int		length;
	int		size;
	char	*str;

	size = ft_check_flag(*&args, format + st) - 1;
	if (!(str = ft_substr(format, st + 1, size)))
		return (-1);
	length = ft_strlen(str);
	args->type = 0;
	ft_arguments_manager(str, *&args, *&arg);
	if (args->error == 1)
		return (-1);
	if (args->type != 0)
		args->zero = 0;
	if (args->dots != 0 && args->max == 0 & args->flag_type == 1)
		args->max = -1;
	if (args->max == -2)
		args->max = 0;
	free(str);
	return (length + 2);
}
