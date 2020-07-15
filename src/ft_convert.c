/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:43:35 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 18:50:03 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert(t_args *args, long long int number)
{
	if (CONV == 'X' || CONV == 'x' || CONV == 'p')
	{
		if (CONV == 'X')
			return (ft_convert_hex(number, 1));
		return (ft_convert_hex(number, 0));
	}
	if (CONV == 'u')
		return (ft_itoa(number));
	return (NULL);
}
