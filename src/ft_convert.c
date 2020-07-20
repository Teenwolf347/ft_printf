/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:43:35 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/20 12:20:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert(t_args *args, long long int num)
{
	if (CONV == 'x' || CONV == 'X' || CONV == 'p')
		return (CONV == 'X' ? ft_convert_hex(num, 1) : ft_convert_hex(num, 0));
	if (CONV == 'u')
		return (ft_itoa(num));
	return (NULL);
}
