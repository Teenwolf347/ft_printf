/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:46:13 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/05 16:52:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_args
{
	int			ptr;
	char		conv;
	int			zero;
	int			start;
	int			width;
	int			minus;
	int			length;
	int			result;
	int			ifprec;
	int			precision;
}				t_args;

int				ft_printf(const char *format, ...);

#endif
