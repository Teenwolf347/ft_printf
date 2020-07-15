/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:26:15 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 19:28:58 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrev(char *str)
{
	int	i;
	int	buf;
	int j;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = 0;
	while (j < i - 1)
	{
		buf = str[i - 1];
		str[i - 1] = str[j];
		str[j] = buf;
		i--;
		j++;
	}
	return (str);
}
