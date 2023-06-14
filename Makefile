# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 20:10:19 by gghaya            #+#    #+#              #
#    Updated: 2023/06/12 18:56:07 by gghaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS =  -Wall -Werror -Wextra
CFILES =  ft_strncmp.c ft_strrchr.c parcing.c get_next_line.c get_next_line_utils.c ft_split.c check.c mlxfunc.c
OFILES = ${CFILES:.c=.o}

all : ${NAME}

${NAME}: ${OFILES} so_long.h ${CFILES}
	${CC}  ${FLAGS} ${OFILES}  -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
%.o:%.c so_long.h
	${CC}  -Imlx -c  ${FLAGS} $<

clean :
	rm -f ${OFILES}
fclean : clean
	rm -f ${NAME}
re : fclean all
.PHONY: clean fclean re all