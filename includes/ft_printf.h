/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:02:21 by tturnber          #+#    #+#             */
/*   Updated: 2020/07/24 23:25:18 by student          ###   ########.fr       */
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
	int			max;
	int			min;
	int			type;
	char		flag;
	int			zero;
	int			dots;
	int			error;
	int			length;
	int			flag_type;
}				t_args;

int				ft_isdigit(int c);
int				ft_get_long(int i);
int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
int				ft_write_char(t_args *args, char str);
int				ft_write_int(t_args *args, int number);
int				ft_write_string(t_args *args, char *str);
int				ft_check_flag(t_args *args, const char *format);
int				ft_write_x(unsigned int number, t_args *args, int t);
int				ft_write_unsigned_int(unsigned int number, t_args *args);
int				ft_write_pointer(unsigned long long number, t_args *args);
int				ft_check_arguments(t_args *args, char *format,
									int st, va_list *arg);
char			*ft_strdup(const char *s1);
char			*ft_substr(const char *s, unsigned int start, size_t len);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_get_int(int d, t_args *args);
void			ft_putnbr_unsigned_int(unsigned int number);
void			ft_write_format(t_args *args, va_list *argptr);
size_t			ft_strlen(const char *s);

#endif
