# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 22:34:58 by gghaya            #+#    #+#              #
#    Updated: 2022/11/16 22:58:46 by gghaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
CFILES = ft_hexa.c ft_putnbr.c ft_putptr.c ft_putchar.c ft_putstr.c ft_putunsigned.c ft_printf.c
OFILES = ${CFILES:.c=.o}

all : ${NAME}

${NAME} : ${OFILES}
	ar -crs ${NAME} ${OFILES}

%.o : %.c ft_printf.h
	${CC} ${FLAGS} -c $<

clean :
	rm -f ${OFILES}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all
