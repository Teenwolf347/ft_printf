/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:02:21 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/26 19:03:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_args
{
	char			type;
	long			width;
	long			precn;
	char			zero;
	char			minus;
	char			pointer;
}					t_args;

typedef struct		s_string
{
	char			*str;
	size_t			length;
}					t_string;

typedef struct		s_numb
{
	long			nbr;
	size_t			length;
}					t_number;

int					ft_atoi(const char *str);
int					ft_write_char(char c, t_args args);
int					ft_printf(const char *format, ...);
int					ft_write_string(char *str, t_args args);
int					ft_write_format(va_list argptr, int result,
									t_args args);
int					ft_write_number(long number, int type,
									int cap, t_args args);
int					ft_length_number(long number, int type);
int					ft_write_pointer(long number, int type, t_args args);
void				ft_putchar_fd(char c, int fd);
void				ft_printf_putchar(int c, int length);
void				ft_putstr_fd(char *s, int fd, int length);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_printf_putnbr(long number, int fd, size_t type, int cap);
const char			*ft_printf_format(va_list argptr,
									const char *format, t_args *args);
size_t				ft_strlen(const char *s);

#endif
