/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:53:19 by tturnber          #+#    #+#             */
/*   Updated: 2020/05/19 17:11:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		i = 0;
		while (s[start + i] && i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
