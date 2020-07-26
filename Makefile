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
	src/ft_memchr.c \
	src/ft_printf_putnbr.c \
	src/ft_printf.c \
	src/ft_printf_format.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_strlen.c \
	src/ft_write_string_or_char.c \
	src/ft_write_format.c \
	src/ft_write_number.c \
	src/ft_write_pointer.c

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

re: fclean all