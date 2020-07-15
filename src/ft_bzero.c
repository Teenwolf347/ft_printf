/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:53:26 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 19:39:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		*ft_bzero(size_t n)
{
	void	*dst;

	if (!(dst = (void *)malloc(n)))
		return (NULL);
	ft_memset(dst, '\0', n);
	return (dst);
}
