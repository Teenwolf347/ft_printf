/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:50:28 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 18:55:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_convert_hex(unsigned long int number, int t)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_bzero(17);
	if (number == 0)
		str[i] = '0';
	if (t == 0)
		while (number != 0)
		{
			str[i] = "0123456789abcdef"[number % 16];
			number /= 16;
			i++;
		}
	else
		while (number != 0)
		{
			str[i] = "0123456789ABCDEF"[number % 16];
			number /= 16;
			i++;
		}
	return (ft_strrev(str));
}
