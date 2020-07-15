/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:02:30 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 19:05:41 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_prec(char *str, t_args *args)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "0x") == 0)
	{
		if (PTR)
			while (str[i])
			{
				ft_putchar_prec(str[i], args);
				i++;
			}
		PTR = 0;
	}
	else
		while (str[i])
		{
			ft_putchar_prec(str[i], args);
			i++;
		}
}
