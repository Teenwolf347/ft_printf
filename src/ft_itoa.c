/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:18:48 by tturnber          #+#    #+#             */
/*   Updated: 2020/05/18 21:46:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa(long int nbr)
{
	long		sign;
	long		count;
	char		*str;

	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	str = (char *)malloc(count + 1);
	str[count] = '\0';
	if (nbr == -2147483648)
		return ("-2147483648");
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	return (str);
}

