# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 20:10:19 by gghaya            #+#    #+#              #
#    Updated: 2023/06/17 15:56:48 by gghaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
FLAGS =  -Wall -Werror -Wextra
CFILES =  ft_strncmp.c ft_strrchr.c parcing.c get_next_line.c get_next_line_utils.c utils_solong.c check.c mlxfunc.c back_tracking.c mlxfunc2.c
OFILES = ${CFILES:.c=.o}
PRINTFDIR = ft_printf
PRINTF = ft_printf/libftprintf.a

all : ${NAME}

${NAME}: ${OFILES} so_long.h ${CFILES}  ${PRINTF}
	${CC}  ${FLAGS}  ${PRINTF} ${OFILES} -lmlx -framework OpenGL -framework AppKit -o ${NAME}
${PRINTF}:
	${MAKE} -C ${PRINTFDIR}
%.o:%.c so_long.h
	${CC} -Imlx -c  ${FLAGS} $<

clean :
	rm -f ${OFILES}
	${MAKE} clean -C ${PRINTFDIR}
fclean : clean
	rm -f ${NAME}
	${MAKE} fclean -C ${PRINTFDIR}
re : fclean all
.PHONY: clean fclean re all