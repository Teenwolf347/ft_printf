# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturnber <tturnber@MSK.21-SCHOOL.RU>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 19:18:52 by tturnber          #+#    #+#              #
#    Updated: 2020/07/16 19:19:46 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SRCS = src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_convert_hex.c \
	src/ft_convert.c \
	src/ft_format_check.c \
	src/ft_itoa.c \
	src/ft_memset.c \
	src/ft_printf_char_string.c \
	src/ft_printf_write_format.c \
	src/ft_printf_write_int.c \
	src/ft_printf_write_pointer.c \
	src/ft_printf_write_precision.c \
	src/ft_printf_write_unsig_int.c \
	src/ft_printf.c \
	src/ft_putchar_prec.c \
	src/ft_putnbr_prec.c \
	src/ft_putstr_prec.c \
	src/ft_strcmp.c \
	src/ft_strlen.c \
	src/ft_strrev.c

OBJS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(OBJS) $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean all