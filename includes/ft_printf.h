/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:46:13 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/15 18:05:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define PTR args->ptr
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
int				ft_strcmp(char *s1, char *s2);
int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
void			*ft_bzero(size_t n);
void			ft_putchar_prec(char c, t_args *args);
void			*ft_memset(void *b, int c, size_t len);
void			ft_printf_write_precision(t_args *args);
void			ft_putstr_prec(char *str, t_args *args);
void			ft_putnbr_prec(long int number, t_args *args);
void			ft_printf_write_int(t_args *a, va_list argptr);
void			ft_printf_write(int start, int i, char *format);
void			ft_printf_write_char(t_args *args, va_list argptr);
void			ft_printf_write_pointer(t_args *args, va_list argp);
void			ft_printf_write_string(t_args *args, va_list argptr);
void			ft_printf_write_format(t_args *args, va_list argptr);
void			ft_format_check(char *f, int *i, t_args *args, va_list argptr);
char			*ft_itoa(int n);
char			*ft_strrev(char *str);
char			*ft_convert(t_args *args, long long int number);
char			*ft_convert_hex(unsigned long int number, int t);
#endif
