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

static size_t	ft_length(int n)
{
	size_t		length;

	length = 0;
	if (n < 0)
	{
		n = n * (-1);
		length++;
	}
	while (n /= 10)
		length++;
	length++;
	return (length);
}

char			*ft_itoa(int n)
{
	long		nb;
	size_t		length;
	char		*str;

	length = ft_length(n);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	length--;
	nb = n;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
	}
	while (nb != 0)
	{
		str[length] = (nb % 10) + '0';
		length--;
		nb /= 10;
	}
	return (str);
}
