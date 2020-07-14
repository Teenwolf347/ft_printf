/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:46:13 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/14 19:23:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define CONV args->conv
# define ZERO args->zero
# define START args->start
# define WIDTH args->width
# define MINUS args->minus
# define LENGTH args->length
# define RESULT args->result
# define IFPREC args->ifprec
# define PRECISION args->precision

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

int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
void			ft_printf_write_precision(t_args *args);
void			ft_putchar_precision(char c, t_args *args);
void			ft_printf_write(int start, int i, char *format);
void			ft_printf_write_char(t_args *args, va_list argptr);
void			ft_printf_write_string(t_args *args, va_list argptr);
void			ft_printf_write_format(t_args *args, va_list argptr);
void			ft_format_check(char *f, int *i, t_args *args, va_list argptr);

#endif
