/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:15:58 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/20 12:14:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = b;
	while (i < len)
		tmp[i++] = c;
	return (b);
}
